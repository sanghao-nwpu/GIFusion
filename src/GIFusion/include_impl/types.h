#include <Eigen/Core>



typedef struct filter_state_t
{
    /* data */
    double time_stamp;
    Eigen::Vector2d pos;
    double yaw;
    double velo;
    double acc;
    double acc_bias;
    Eigen::MatrixXd cov;
} filter_state_t;


