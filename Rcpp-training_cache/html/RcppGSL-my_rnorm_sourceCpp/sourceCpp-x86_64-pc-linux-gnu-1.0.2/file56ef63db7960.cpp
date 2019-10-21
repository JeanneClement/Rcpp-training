#include <Rcpp.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
using namespace Rcpp;
// [[Rcpp::depends(RcppGSL)]]
// [[Rcpp::export]]
Rcpp::NumericVector my_rnorm(int nsamp, double mu,
                             double sigma) {
	gsl_rng *s = gsl_rng_alloc(gsl_rng_mt19937); // Random seed
	Rcpp::NumericVector beta(nsamp);
	for (int i = 0; i < nsamp; i++) {
		beta[i] = mu + gsl_ran_gaussian(s, sigma); // Random draw
	}
	return beta;
}
