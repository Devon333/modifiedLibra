/*********************************************************************************
* Copyright (C) 2015-2022 Alexey V. Akimov
*
* This file is distributed under the terms of the GNU General Public License
* as published by the Free Software Foundation, either version 3 of
* the License, or (at your option) any later version.
* See the file LICENSE in the root directory of this distribution
* or <http://www.gnu.org/licenses/>.
*
*********************************************************************************/

#ifndef MODEL_ECWR_H
#define MODEL_ECWR_H

#include "../math_linalg/liblinalg.h"

/// liblibra namespace
namespace liblibra{

using namespace liblinalg;


namespace libmodels{


void model_ECWR(CMATRIX& Hdia, CMATRIX& Sdia, vector<CMATRIX>& d1ham_dia, vector<CMATRIX>& dc1_dia,
                vector<double>& q, vector<double>& params);

void ECWR_Ham(double x, MATRIX* H, MATRIX* dH, MATRIX* d2H, vector<double>& params_);
boost::python::list ECWR_Ham(double x, boost::python::list params_);


}// namespace libmodels
}// liblibra


#endif // MODEL_ECWR
