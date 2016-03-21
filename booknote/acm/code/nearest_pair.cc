/**
 * @file nearest_pair.cc
 * @brief looks for the nearest pair of points with brute force
 */
#include <iostream>
#include <vector>
#include <cmath>
#include "vectorutil"

/**
 * @struct 2-d point
 */
struct coordinate2d {
	float x;
	float y;
};

/**
 * @brief calculate the euclidean distance between two points
 * @param [struct coordinate2d] the first point
 * @param [struct coordinate2d] the second point
 * @return the euclidean distance between the two points
 */
float
euclidean_distance (struct coordinate2d a, struct coordinate2d b)
{
	return sqrtf(
		(a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)
	);
}

/**
 * @brief implement finding nearest pair
 * @param [std::vector<struct coordinate2d>] a vector of points
 * @return [std::vector<int>] a vector of size a containing the nearest pair
 */
std::vector<int>
nearest_pair (std::vector<struct coordinate2d> buf)
{
	if (0 == buf.size()) return std::vector<int> { -1, -1 };
	int mina = 0, minb = 1;
	float mindist = euclidean_distance(buf[0], buf[1]);
	// scan for all combinations
	for (unsigned int i = 0; i < buf.size(); i++) {
		for (unsigned int j = 0; j < buf.size(); j++) {
			// don't compare with itself
			if (i == j) continue;
			// scan for min
			if (mindist > euclidean_distance(buf[i], buf[j])) {
				// update
				mindist = euclidean_distance(buf[i], buf[j]);
				mina = i;
				minb = j;
			}
		}
	}
	// construct vector
	std::vector<int> ret;
	ret.push_back(mina);
	ret.push_back(minb);
	return ret;
}

/**
 * @brief test brute force nearest pair
 */
int
main (void)
{
	// preapre points
	std::vector<struct coordinate2d> buf;
	struct coordinate2d p0 = { 0., 1. };
	struct coordinate2d p1 = { 1., 100. };
	struct coordinate2d p2 = { 5., 5. };
	struct coordinate2d p3 = { 10., 0. };
	struct coordinate2d p4 = { 1., 101. };
	buf.push_back(p0);
	buf.push_back(p1);
	buf.push_back(p2);
	buf.push_back(p3);
	buf.push_back(p4);
	vector_dump(nearest_pair(buf));

	return 0;
}
