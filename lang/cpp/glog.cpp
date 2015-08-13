#include <glog/logging.h>
#include <unistd.h>

int
main (int argc, char **argv) {
	// Log messeages into stderr
	FLAGS_logtostderr = 1;
	// init
	google::InitGoogleLogging (argv[0]);
	LOG_IF(INFO, 1 == FLAGS_logtostderr) << "FLAG logging to stderr is set";
	LOG(INFO) << "Hello Glog ! ";
	LOG(WARNING) << "warn";
	PCHECK( 0 <= write(1,NULL,2) ) << "write() NULL failed";
	LOG(ERROR) << "error";
	LOG(FATAL) << "fatal, then by default dump stack trace";
	return 0;
}
