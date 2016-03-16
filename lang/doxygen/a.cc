/**
 * @file
 * @author lumin zhou <lumin@example.org>
 * @version 0.1
 *
 * @section LICENSE
 *
 * MIT License
 *
 * @section DESCRIPTION
 *
 */

#include <iostream>

/// @brief hello() write your function description here
/// @param [in] i  the number that will be printed
/// @return void
/// @remark this is a remark
/// @note this is a note
/// @code 
/// example code, end at endcode
/// @endcode
/// @see see some references.
/// @see http://www.doxygen.nl/manual/index.html
void
hello (int i)
{
	std::cout << "hello! " << i << std::endl;
	return;
}


/**
 * A short line description
 *
 * @param argc input param void
 * @return return 0 in int
 *
 * a displayed equation: @f[ e^{i\pi} + 1 = 0 @f]
 *
 * @note note that that
 * - item 1
 * - item 2
 *
 * @see https://en.wikipedia.org/wiki/Doxygen
 * @see http://www.doxygen.nl/
 * @see http://blog.csdn.net/augusdi/article/details/6749845
 *
 */
int
main (int argc)
{
	hello();
	return 0;
}
