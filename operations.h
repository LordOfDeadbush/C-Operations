const double E = 2.71828182845904523536;
const double PI = 3.14159265358979323846;
const double MAX_DECIMAL_PRECISION = 7;


double _int_pow(double x, int n) {
    double result = 1;
    for (int i = 0; i < abs(n); i++) {
        result *= x;
    }
    if (n > 0) return result;
    else return 1 / result;
}

/*
Our approach:
estimate the root by digit: first, iterate through numbers until we find a number that, when put 
to the power of n, returns a number greater than the original number. We proceed with the number
just below, and continue to the next step.
we then do this for the first fifteen digits after the decimal 
*/
double _int_root(double x, int n) { // this version of root is to find the nth root of a number where n is an integer
    int exp = abs(n);
    double root = 0;

    while (_int_pow(root, exp) < x) { root++; }
    root--; // * this is to keep root^2 < x so we can use that to evaluate the decimal points
    if (_int_pow(root, n) == x) return root;
    for (int i = 1; i < MAX_DECIMAL_PRECISION; i++) {
        double step = _int_pow(0.1, i);
        double j;
        for (j = root; j < root + (step * 10); j += step) {
            double test = _int_pow(j, n);
            if (test >= x) {
                j -= step;
                break;
            }
        }
        root = j;
    }
    return root;
}


double abs(double x) {
    if (x < 0) return -x;
    return x;
}

double ln(double x) {
    // explanation here: https://en.wikipedia.org/wiki/Natural_logarithm#Integral_definition
    double sum = 0;
    double step = _int_pow(0.1, 15);
    for (double i = 1; i < x; i += step) {
        sum += step * (1 / i);
    }
    return sum;
}

double log(double x, double n) { // in the form log sub a
    return ln(x) / ln(n);
}

double floor(double x) { return (int) x; }
double ceil(double x) { return ((int) x) + 1; }

int round(double x) {
    double f = floor(x);
    double decimal = x - f;
    if (decimal > 0.5) { return f + 1; }
    return f;
}

/*
explanation of pow inplementation:
for pow, we need to do this:
a^(bc/c)
here we creatively use the root function:
root[c](a)^bc
this is so we dont get partial roots.
a possibility is to run this through multiple times so we get a better approximation (if we make better root function)
*/
double pow(double x, double n) {
    double exp_const = pow(10, MAX_DECIMAL_PRECISION);
    return _int_pow(_int_root(x, exp_const), exp_const * n);
}