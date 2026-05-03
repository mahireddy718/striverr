// User function Template for C++
// if only 3 digit n.o is given
class Solution {
  public:
    bool armstrongNumber(int n) {
        int original=n;
        int sum=0;
        while(n>0){
            int digit=n%10;
            sum+=pow(digit,3);
            n=n/10;
        }
        if(original==sum)return true;
        else{
            return false;
        }
    }
};