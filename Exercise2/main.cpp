#include <iostream>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;


int main()
{
	Matrix2d A1 {{5.547001962252291e-01,-3.770900990025203e-02},{8.320502943378437e-01,-9.992887623566787e-01}};
	Vector2d b1 {-5.169911863249772e-01,1.672384680188350e-01};
	Matrix2d A2 {{5.547001962252291e-01,-5.540607316466765e-01},{8.320502943378437e-01,-8.324762492991313e-01}};
	Vector2d b2 {-6.394645785530173e-04,4.259549612877223e-04};
	Matrix2d A3 {{5.547001962252291e-01,-5.547001955851905e-01},{8.320502943378437e-01,-8.320502947645361e-01}};
	Vector2d b3 {-6.400391328043042e-10, 4.266924591433963e-10};
	Vector2d x { -1.0e+0,-1.0e+00};
	Vector2d x1_lup;
	if (abs(A1.determinant())>1.0e-12)
		x1_lup = A1.partialPivLu().solve(b1);
	else
		x1_lup = A1.fullPivLu().solve(b1);
	cout.precision(16);
	double err_rel_1_lup = ((x-x1_lup).norm())/((x).norm());
	cout<< scientific <<"err_rel_1_lup= " << err_rel_1_lup<<endl;
	Vector2d x1_qr;
	x1_qr = A1.colPivHouseholderQr().solve(b1);
	double err_rel_1_qr = ((x-x1_qr).norm())/((x).norm());
	cout<< "err_rel_1_qr= " << err_rel_1_qr<<endl;
	
	Vector2d x2_lup;
	if (abs(A2.determinant())>1.0e-12)
		x2_lup = A2.partialPivLu().solve(b2);
	else
		x2_lup = A2.fullPivLu().solve(b2);
	double err_rel_2_lup = ((x-x2_lup).norm())/((x).norm());
	cout <<"err_rel_2_lup= " << err_rel_2_lup<<endl;
	Vector2d x2_qr;
	x2_qr = A2.colPivHouseholderQr().solve(b2);
	double err_rel_2_qr = ((x-x2_qr).norm())/((x).norm());
	cout<< "err_rel_2_qr= " << err_rel_2_qr<<endl;
	
	
	Vector2d x3_lup;
	if (abs(A3.determinant())>1.0e-12)
		x3_lup = A3.partialPivLu().solve(b3);
	else
		x1_lup = A3.fullPivLu().solve(b3);
	double err_rel_3_lup = ((x-x3_lup).norm())/((x).norm());
	cout<< scientific <<"err_rel_3_lup= " << err_rel_3_lup<<endl;
	Vector2d x3_qr;
	x3_qr = A3.colPivHouseholderQr().solve(b3);
	double err_rel_3_qr = ((x-x3_qr).norm())/((x).norm());
	cout<< "err_rel_3_lup= " << err_rel_3_qr<<endl;
    return 0;
}
