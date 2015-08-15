#include <glog/logging.h>
#include <string>

template <typename T>
T abs (T x)
{
	return (x > 0)? x : -x;
}
// end function template

// this is a class template
template <typename T>
class food {
	private:
		T label;
		T color;
	public:
		food (T label, T color); // constructor
		void dump();
};

//template <typename T>
//food<T>::food(T label, T color):label(label),color(color){}
template <typename T>
food<T> :: food(T _label, T _color) {
	label = _label;
	color = _color;
}

template <typename T>
void food<T>::dump()
{
	LOG(INFO) << "Dump: label = " << label << "; color = " << color;
	return;
}
// end class template

int
main (int argc, char **argv) {
	// Log messeages into stderr
	FLAGS_logtostderr = 1;
	// init
	google::InitGoogleLogging (argv[0]);

	LOG(INFO) << "testing function template";
	LOG(INFO) << abs(-1.7);
	LOG(INFO) << abs(1.1);
	LOG(INFO) << abs(-10);
	LOG(INFO) << abs('a');
	LOG(INFO) << "function template test done.";

	LOG(INFO) << "";

	LOG(INFO) << "testing class template";
	food<int> apple (1, 2);
	apple.dump();
	food<std::string> banana ("ba", "yell");
	banana.dump();
	LOG(INFO) << "class template test done.";

	return 0;
}
