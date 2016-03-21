/**
 * @file convex.cc
 * @brief finds out convex hull
 */
#include <iostream>
#include <vector>
#include <cmath>
#include "vectorutil"
#include <assert.h>

int debug = 1;

/**
 * @struct 2-d point
 */
struct point2d {
	float x;
	float y;
};

/**
 * @brief calculate the euclidean distance between two points
 * @param [struct point2d] the first point
 * @param [struct point2d] the second point
 * @return the euclidean distance between the two points
 */
float
euclidean (struct point2d a, struct point2d b)
{
	return sqrtf(
		(a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)
	);
}

/**
 * @brief find all candidate edges for convex hull
 * @param [std::vector<struct point2d> &] a set of points
 * @return [std::vector<std::vector<int> >] all satisfied pairs, not ordered
 */
std::vector<std::vector<int> *>
convex_find_candidates (std::vector<struct point2d> buf)
{
	std::vector<std::vector<int> *> ret;
	// for every pairs : loop 1 for i
	for (unsigned int i = 0; i < buf.size(); i++) {
		// for every pairs : loop 2 for j
		for (unsigned int j = i; j < buf.size(); j++) {
			// don't draw line with itself
			if (i == j) continue;
			if (debug) std::cout << "Iter (" << i << "," << j << ")" << std::endl;
			// statistic counter for point distribution
			int eq = 0, lt = 0, gt = 0;
			/// first construct a equation with point i and point j
			/// @f[ ax + by = c @f]
			/// where x and y is known, and we need to find out
			/// a, b and c with help with point i and point j
			/// the solutions is
			/// @f[ a = y_2 - y_1, b = x_1 - x_2, c = x_1 y_2 - y_1 x_2 @f]
			float a = buf[j].y - buf[i].y;
			float b = buf[i].x - buf[j].x;
			float c = buf[i].x * buf[j].y - buf[i].y * buf[j].x;
			std::cout << "a=" << a << " b=" << b << " c=" << c << std::endl;
			// test every points except for i and j
			for (unsigned int k = 0; k < buf.size(); k++) {
				if (k==i || k==j) continue;
				float left = a * buf[k].x + b * buf[k].y;
				if (left == c)
					eq++;
				else if (left > c)
					gt++;
				else if (left < c)
					lt++;
				else
					std::cout << "ERROR!";
			}
			// check result
			if (0 == lt || 0 == gt) {
				std::vector<int> * sat = new std::vector<int>;
				sat->push_back(i);
				sat->push_back(j);
				ret.push_back(sat);
			} else 
				continue; // not satisfied.
		}
	}
	return ret;
}

/**
 * @brief find the path from generated candidates
 * @param [std::vector<std::vector<int> *> &] edge candidates
 * @return sorted candidates list
 */
std::vector<std::vector<int> *>
convex_sort_candidates (std::vector<std::vector<int> *> & buf)
{
	std::vector<int> * start_point = buf[0];
	// start from the first point in the vector, so skip [0]
	for (unsigned int i = 1; i < buf.size(); i++) {
		// find the right point for i-th place
		std::vector<int> * cursor = buf[i-1];
		for (unsigned int j = i; j < buf.size(); j++) {
			if (buf[j]->at(0) == cursor->at(1)) {
				// they can be linked, put this one to i-th
				std::vector<int> * tmp = buf[i];
				buf[i] = buf[j];
				buf[j] = tmp;
			} else if (buf[j]->at(1) == start_point->at(0)) {
				// it can be linked to the start_point
				;
			}
		}
	}
	return buf;
}

/**
 * @brief test brute force nearest pair
 */
int
main (void)
{
	// preapre points
	std::vector<struct point2d> buf;
	struct point2d p0 = { 0., 0. };
	struct point2d p1 = { 2., 0. };
	struct point2d p2 = { 2., 2. };
	struct point2d p3 = { 0., 2. };
	struct point2d p4 = { 1., 1. };
	buf.push_back(p0);
	buf.push_back(p1);
	buf.push_back(p2);
	buf.push_back(p3);
	buf.push_back(p4);

	std::vector<std::vector<int> *> candidates = convex_find_candidates(buf);
	std::cout << "dump candidates";
	for (unsigned int i = 0; i < candidates.size(); i++)
		vector_dump(*candidates[i]);

	convex_sort_candidates (candidates);
	std::cout << "dump sorted candidates, the convex solution";
	for (unsigned int i = 0; i < candidates.size(); i++)
		vector_dump(*candidates[i]);

	return 0;
}
