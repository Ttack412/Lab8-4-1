    #include <iostream>

    using namespace std;
    
    class Matrix{
    public:
        Matrix(int A, int B, int C, int D){
        int values[4] = {A,B,C,D};
        
            for(int e=0; e<4; e++){
                for(int o=0; o<2; o++){
                    for(int i=0; i<2; i++){
			  v[o][i] = values[e];
                    }
                }
            }
        }
        
        void print(ostream &os) const {
            
            os << v[0][0] << " " << v[0][1] << endl;
            os << v[1][0] << " " << v[1][1] << endl;
            os << "- - - - - -" << endl;
         }
        
        void add(const int& rhs){
            for(int o = 0; o<2; o++){
                for(int i = 0; i<2; i++){
                    v[o][i] += rhs;
                }
            }
        }
        
        void add(const Matrix& m){
            for(int o = 0; o<2; o++){
                for(int i = 0; i<2; i++){
                    v[o][i] += m.v[o][i];
                }
            }
        }
        
        void sub(const int& rhs){
            for(int o = 0; o<2; o++){
                for(int i = 0; i<2; i++){
                    v[o][i] -= rhs;
                }
            }
        }
        
        void sub(const Matrix& m){
            for(int o = 0; o<2; o++){
                for(int i = 0; i<2; i++){
                    v[o][i] -= m.v[o][i];
                }
            }
        }
        void operator+(const int& rhs){
            add(rhs);
        }
        
        void operator+(const Matrix& m){
            add(m);
        }
        
        void operator-(const int& rhs){
            sub(rhs);
        }
        
        void operator-(const Matrix& m){
            sub(m);
        }
    private:
        int v[2][2];
    };
    
    int main(){
        Matrix m1(1,1,1,1);
        Matrix m2(2,2,2,2);
        
        cout << "Staring Matrix 1" << endl;
        m1.print(cout);
        
        cout << "Staring Matrix 2" << endl;
        m2.print(cout);
        
        cout << "Adding and Subtracting values to every cell in the matrix"<<endl;
        cout << "- - - - - -" << endl;
        
        cout << "Adding values with the method" << endl;
        m1.add(1);
        m1.print(cout);
        
        cout << "Adding values with the operator" << endl;
        m1+1;
        m1.print(cout);
        
        cout << "Subtracting values with the operator" << endl;
        m1-1;
        m1.print(cout);
        
        cout << "Subtracting values with the method" << endl;
        m1.sub(1);
        m1.print(cout);
        
        cout << "Adding and Subtracting the values in every cell of each matrix" <<endl;
        cout << "- - - - - -" << endl;
        
        cout << "Adding matrices with the method" << endl;
        m1.add(m2);
        m1.print(cout);
        
        cout << "Adding matrices with the operator" << endl;
        m1+m2;
        m1.print(cout);
        
        cout << "Subtracting matrices with the operator" << endl;
        m1-m2;
        m1.print(cout);
        
        cout << "Subtracting matrices with the method" << endl;
        m1.sub(m2);
        m1.print(cout);
    }