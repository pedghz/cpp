#include <iostream>

using namespace std;

class fractional {
   public:
    fractional(int num = 0, int denum = 1);

    fractional mul(fractional right_side) const;

    fractional dev(fractional right_side) const;

    fractional add(fractional right_side) const;

    fractional sub(fractional right_side) const;

    void print() const;


    private:
     int numerator_;
     int denuminator_;
};

fractional::fractional(int numer, int denum): numerator_(numer),denuminator_(denum){
}

void fractional::print() const {
    cout << numerator_ << "/" << denuminator_ << endl;
}

fractional fractional::mul(fractional right_side) const {
    fractional result(numerator_ * right_side.numerator_, denuminator_ * right_side.denuminator_);
    return (result);
}

fractional fractional::dev(fractional right_side) const {
    fractional result(numerator_ * right_side.denuminator_, denuminator_ * right_side.numerator_);
    return (result);

}

fractional fractional::add(fractional right_side) const {
    fractional result((numerator_ * right_side.denuminator_) + (denuminator_ * right_side.numerator_), denuminator_ * right_side.denuminator_);
    return (result);

}

fractional fractional::sub(fractional right_side) const {
    fractional result((numerator_ * right_side.denuminator_) - (denuminator_ * right_side.numerator_), denuminator_ * right_side.denuminator_);
    return (result);
}
int main( ) {
    fractional num1(4,5);
    fractional num2(5,8);
    fractional num3(1,8);
    fractional num4(2,3);
    fractional num5(1,7);
    fractional result;
    fractional result2;
    result = num1.sub(num2);
    result = result.add(num3);
    result2 = num4.mul(num5);
    result = result.dev(result2);

    result.print();


}
