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

#include "Model_Rabi2.h"

/// liblibra namespace
namespace liblibra{

using namespace liblinalg;


/// libmodels namespace
namespace libmodels{


void Rabi2_Ham(double x, MATRIX* H, MATRIX* dH, MATRIX* d2H, vector<double>& params){ 
// Rabi2 hamiltonian in diabatic representation

  if(H->n_elts!=4){ std::cout<<"Error in Rabi2_Ham: H matrix must be allocated\n"; exit(0);}
  if(dH->n_elts!=4){ std::cout<<"Error in Rabi2_Ham: dH matrix must be allocated\n"; exit(0);}
  if(d2H->n_elts!=4){ std::cout<<"Error in Rabi2_Ham: d2H matrix must be allocated\n"; exit(0);}


  double e;


  // Default parameters
  double A = -0.010;  double B = 0.010;
  double C = 0.005;  

  if(params.size()>=3){
    A = params[0];    B = params[1];
    C = params[2];   
  }

  // H00
  H->M[0] = A;
  dH->M[0] = 0.0;
  d2H->M[0] = 0.0;

  // H11
  H->M[3] = B; 
  dH->M[3] = 0.0;
  d2H->M[3] = 0.0;
  
  // H01 and H10
  H->M[1] = H->M[2] = C;
  dH->M[1] = dH->M[2] = 0.0;
  d2H->M[1] = d2H->M[2] = 0.0;


}

boost::python::list Rabi2_Ham(double x, boost::python::list params_){ 
// SAC hamiltonian in diabatic representation

  MATRIX H(2,2);
  MATRIX dH(2,2);
  MATRIX d2H(2,2);

  int sz = boost::python::len(params_);
  vector<double> params(sz,0.0);
  for(int i=0;i<sz;i++){ params[i] = boost::python::extract<double>(params_[i]);  }

  Rabi2_Ham(x,&H,&dH,&d2H,params);

  boost::python::list res;
  res.append(x);
  res.append(H);
  res.append(dH);
  res.append(d2H);
 
  return res;

}

}// namespace libmodels
}// liblibra
