#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Define the data points
    vector<double> x{0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
    vector<double> y{1.0, 2.0, 5.0, 10.0, 17.0, 26.0};
    
    // Define the degree of the polynomial to fit
    int degree = 2;
    
    // Create the X matrix
    int num_points = x.size();
    vector<vector<double>> X(num_points, vector<double>(degree + 1, 1.0));
    for (int i = 0; i < num_points; i++) {
        for (int j = 1; j <= degree; j++) {
            X[i][j] = pow(x[i], j);
        }
    }
    
    // Calculate the coefficients of the polynomial
    vector<double> X_transpose_times_y(degree + 1, 0.0);
    vector<vector<double>> X_transpose_times_X(degree + 1, vector<double>(degree + 1, 0.0));
    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j <= degree; j++) {
            X_transpose_times_y[j] += X[i][j] * y[i];
            for (int k = 0; k <= degree; k++) {
                X_transpose_times_X[j][k] += X[i][j] * X[i][k];
            }
        }
    }
    vector<double> coefficients(degree + 1, 0.0);
    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= degree; j++) {
            coefficients[i] += X_transpose_times_X[i][j] * X_transpose_times_y[j];
        }
    }
    
    // Output the results
    cout << "Coefficients: ";
    for (int i = 0; i <= degree; i++) {
        cout << coefficients[i] << " ";
    }
    cout << endl;
    
    return 0;
}
