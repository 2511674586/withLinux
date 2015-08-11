#include <glog/logging.h>

int
main (int argc, char **argv) {
	// Log messeages into stderr
	FLAGS_logtostderr = 1;
	google::InitGoogleLogging (argv[0]);
	LOG_IF(INFO, 1 == FLAGS_logtostderr) << "FLAG: logging to stderr";
	LOG(INFO) << "Hello Glog ! ";
	LOG(WARNING) << "warn";
	LOG(ERROR) << "error";
	LOG(INFO) << "done";
	LOG(FATAL) << "fatal";
	return 0;
}
