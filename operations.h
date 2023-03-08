const double E = 2.71828182845904523536;
const double PI = 3.14159265358979323846;
const double SUM_STEP_SIZE = 1e-7;

double root(double x, int y) {

}

double ln(double x) {
    // explanation here: https://en.wikipedia.org/wiki/Natural_logarithm#Integral_definition
    double sum = 0;
    for (double i = 1; i < x; i += SUM_STEP_SIZE) {
        sum += SUM_STEP_SIZE * (1 / i);
    }
    return sum;
}

double log(double x, double a) { // in the form log sub a
    return ln(x) / ln(a);
}