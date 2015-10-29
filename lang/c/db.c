/* http://www.ibm.com/developerworks/cn/linux/l-embdb/index.html */
/* http://web.stanford.edu/class/cs276a/projects/docs/berkeleydb/api_c/db_list.html */

/* handle struct : DB
   (* dosth)(DB *, arg ...)
   e.g. open(), close(), put(), get()

   record struct : DBT
   void* data
   u_int32_t size

   cursor struct : DBC

   environment handle : DB_ENV

   all core structures should be initialized before use, and they should be closed after using.
*/
/* algorithms
   B+
   HASH
   Recno
   Queue
*/

/* References
   [1] Berkeley DB source tree, {docs,examples}
*/

#include <db.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* for error report */
void
_dbperror (u_int32_t _st,
	__typeof__(__LINE__) _line, __typeof__(__FILE__) _file)
{
	if (!_st) {
		fprintf (stderr, "E: %s: %d: %s\n", _file, _line,
			db_strerror(_st));
		exit (EXIT_FAILURE);
	}
}
#define dbperror(_st) do { \
	_dbperror(_st, __LINE__, __FILE__); \
} while(0)

void
DBT_memset (DBT * _key, DBT * _data)
{
	memset (_key, 0, sizeof(DBT));
	memset (_data, 0, sizeof(DBT));
}

int
main (int argc, char **argv)
{
	DB * db;
	DBT key, data;
	DBC * dbc;
	int dbst;

	/* create db handle */
	dbst = db_create(&db, NULL, 0);
	if (dbst) dbperror (dbst);

	/* create db and setup cursor */
	dbst = db->open (db, NULL, "_temp.db", NULL, DB_BTREE, DB_CREATE, 0);
	if (dbst) dbperror (dbst);

	db->cursor(db, NULL, &dbc, 0);

	/* prepare data */
	DBT_memset (&key, &data);
	char * key_data = "berkeley";
	int key_size = strlen (key_data) + 1;
	key.data = key_data;
	key.size = key_size;
	int data_data = 1024;
	int data_size = sizeof(int);
	data.data = &data_data;
	data.size = data_size;

	/* put data into db */
	dbst = db->put (db, NULL, &key, &data, DB_NOOVERWRITE);
	if (dbst) dbperror (dbst);

	/* put another set of data into db */
	DBT_memset (&key, &data);
	key_data = "university";
	key_size = strlen (key_data) + 1;
	key.data = key_data;
	key.size = key_size;
	data_data = 2048;
	data_size = sizeof(int);
	data.data = &data_data;
	data.size = data_size;
	dbst = db->put (db, NULL, &key, &data, DB_NOOVERWRITE);
	if (dbst) dbperror (dbst);

	/* sync db */
	db->sync (db, 0);
	sync ();

	/* get the latest set of data and print */
	DBT_memset (&key, &data);
	key.data = key_data;
	key.size = key_size;
	dbst = db->get (db, NULL, &key, &data, 0);
	if (dbst) dbperror (dbst);
	printf ("I: (%s:%d)\n", (char *)key.data, *((int *) data.data));

	/* traverse */
	printf ("I: traverse\n");
	DBT_memset (&key, &data);
	while (0 == (dbst = dbc->c_get(dbc, &key, &data, DB_NEXT))) {
		printf ("I: traverse: (%s:%d)\n", (char *)key.data, *((int *) data.data));
	}

	/* look up */
	DBT_memset (&key, &data);
	key.data = key_data;
	key.size = key_size;
	dbst = dbc->c_get (dbc, &key, &data, DB_SET);
	if (dbst) dbperror (dbst);
	printf ("I: cursor lookup: (%s:%d)\n", (char *)key.data, *((int *) data.data));

	/* close db */
	if (NULL != db) {
		db->close (db, 0);
	}
	
	/* i want to open again */
	printf ("I: open again\n");

	DB * db2;
	dbst = db2->open (db2, NULL, "_temp.db", NULL, DB_BTREE, DB_RDONLY, 0);
	if (dbst) dbperror (dbst);
	/* FIXME: BUG: segfault when open again, why ? */

	return 0;
}
