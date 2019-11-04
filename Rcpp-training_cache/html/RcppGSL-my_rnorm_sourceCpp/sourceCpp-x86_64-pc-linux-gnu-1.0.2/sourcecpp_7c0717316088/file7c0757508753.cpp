#include <Rcpp.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
// [[Rcpp::depends(RcppGSL)]]

using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::NumericVector my_rnorm(int nsamp, double mu,
                             double sigma, int seed) {
  
  // Initialize random seed for random number generator 
  gsl_rng *s = gsl_rng_alloc(gsl_rng_mt19937);
  gsl_rng_set(s, seed);
  
  // Initialize the vector to store results
  Rcpp::NumericVector beta(nsamp);
  
  // Generate a sample of nsamp values from gaussian distribution 
  for (int i = 0; i < nsamp; i++) {
    beta[i] = mu + gsl_ran_gaussian(s, sigma); // Random draw
  }
  
  // Free memory
  gsl_rng_free(s);
  
  return beta;
}


#include <Rcpp.h>
// my_rnorm
Rcpp::NumericVector my_rnorm(int nsamp, double mu, double sigma, int seed);
RcppExport SEXP sourceCpp_1_my_rnorm(SEXP nsampSEXP, SEXP muSEXP, SEXP sigmaSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type nsamp(nsampSEXP);
    Rcpp::traits::input_parameter< double >::type mu(muSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< int >::type seed(seedSEXP);
    rcpp_result_gen = Rcpp::wrap(my_rnorm(nsamp, mu, sigma, seed));
    return rcpp_result_gen;
END_RCPP
}
