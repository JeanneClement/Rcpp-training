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


#include <Rcpp.h>
// my_rnorm
Rcpp::NumericVector my_rnorm(int nsamp, double mu, double sigma);
RcppExport SEXP sourceCpp_1_my_rnorm(SEXP nsampSEXP, SEXP muSEXP, SEXP sigmaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type nsamp(nsampSEXP);
    Rcpp::traits::input_parameter< double >::type mu(muSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    rcpp_result_gen = Rcpp::wrap(my_rnorm(nsamp, mu, sigma));
    return rcpp_result_gen;
END_RCPP
}
