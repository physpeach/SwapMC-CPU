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
        return result;
    }
    template int powInt<int>(int, int);
    template double powInt<double>(double, int);
}