namespace PhysPeach{
    template<typename T>
    T powInt(T a, int x){
        T result = a/a;
        if (x >= 0){
            for (int i = 0; i < x; i++){
                result *= a;
            }
        }else{
            for (int i = 0; i < -x; i++){
                result /= a;
            }
        }
    }
    template int powInt<int>(int, int);
}