#include <vector>
#include "math.h"

using namespace std;

typedef vector<float> Vector;
typedef vector<Vector> Matriz;

void zeroes(Matriz &M, int n){
    for(int i = 0; i < n; i++) {
        Vector row(n, 0.0);
        M.push_back(row);
    }
}

void copyMatriz(Matriz A, Matriz &copy){
    zeroes(copy, A.size());
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.at(0).size(); ++j)
            copy.at(i).at(j) = A.at(i).at(j);
}

void transpose(Matriz M, Matriz &T){
    zeroes(T, M.size());
    for (int i = 0; i < M.size(); ++i)
        for(int j = 0; j < M.at(0).size(); j++)
            T.at(j).at(i) = M.at(i).at(j);
}

void getMenor(Matriz &M, int i, int j){
    M.erase(M.begin()+i);
    for(int i=0;i<M.size();i++)
        M.at(i).erase(M.at(i).begin()+j);
}

float determinant(Matriz M){
    if (M.size() == 1){
        return M.at(0).at(0);
    } else{
        float det = 0.0;
        for (int i = 0; i < M.at(0).size(); ++i){
            Matriz menor;
            copyMatriz(M, menor);
            getMenor(menor, 0, i);
            det += pow(-1, i) * M.at(0).at(i) * determinant(menor);
        }
        return det;
    }
}

void cofactors(Matriz M, Matriz &Cof){
    //Se prepara la matriz de cofactores para que sea de las mismas
    //dimensiones de la matriz original
    zeroes(Cof,M.size());
    //Se recorre la matriz original
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            //Se obtiene el menor de la posicion actual
            Matriz minor;
            copyMatriz(M,minor);
            getMenor(minor,i,j);
            //Se calcula el cofactor de la posicion actual
            //      alternante * determinante del menor de la posicion actual
            Cof.at(i).at(j) = pow(-1,i+j)*determinant(minor);
        }
    }
}

void divisionRealMatriz(float real, Matriz M, Matriz &R){
    zeroes(R, M.size());
    for (int i = 0; i < M.size(); ++i)
        for (int j = 0; j < M.at(0).size(); ++j){
            R.at(i).at(j) = M.at(i).at(j) / real;
        }

}

void inversaMatriz(Matriz A, Matriz &inv){
    Matriz trans, cof;
    float det;
    det = determinant(A);
    if (det == 0){
        cout << "No se puede calcular porque el determinante es 0!!!!";
        exit(EXIT_FAILURE);
    } else{
        cofactors(A, cof);
        transpose(cof, trans);
        divisionRealMatriz(det, trans, inv);
    }
}