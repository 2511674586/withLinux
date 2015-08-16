#include <glog/logging.h>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#define INFO LOG(INFO)

using namespace std;

int
main (int argc, char **argv) {
	// Log messeages into stderr
	FLAGS_logtostderr = 1;
	// init
	google::InitGoogleLogging (argv[0]);

	INFO << "take a look at http://www.cplusplus.com/";

	INFO << "generate integer vector";
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	INFO << "sorting then dump";
	sort (v.begin(), v.end());
	for (unsigned int i = 0; i < v.size(); i++) {
		INFO << v[i] << " ";
	}
	INFO << "";

	INFO << "generating list";
	list<int> l;
	l.push_back(11);
	l.push_back(33);
	l.push_back(22);
	l.push_back(44);
	INFO << "sorting list then dump";
	l.sort();
	while (l.size() > 0) {
		INFO << l.front() << " ";
		l.pop_front();
	}

	INFO << "done";
	return 0;
}
