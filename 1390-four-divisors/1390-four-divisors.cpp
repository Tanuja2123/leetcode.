class Solution {
public:
    int sfour(int num){
        int div=0;
        int sum=0;
        for(int i=1; i*i<= num; i++){
            if(num%i==0){
                int other= num/i;
                if(i==other){
                    div++;
                    sum += i;
                } else{
                    div +=2;
                    sum += (i+other);
                }
            }
            if(div > 4) return 0;
        }
        if(div == 4){
            return sum;
        }
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        for(int &num: nums){
            res+= sfour(num);
        }
        return res;
    }
};