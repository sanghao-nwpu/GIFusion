// GIFusionInterface.h


#ifndef GIFUSION_INTERFACE_H
#define GIFUSION_INTERFACE_H

#include <memory>

typedef enum status_e
{
    STATUS_NORMAL = 0,
    STATUS_WARNING = 1,
    STATUS_ERROR = 2
} status_e;

typedef struct gi_imu_t
{
    double timestamp;
    double accel[3];
    double gyro[3];
    int status;
} gi_imu_t;

typedef struct gi_gnss_t
{
    /* data */
    double timestamp;
    double blh[3];  /** blh: latitude, longitude, height */
    double vel[3];  /** vel: velocity in ENU frame */
    double hdop;
    int blh_status; /** 0: invalid, 1: valid */
    int vel_status; /** 0: invalid, 1: valid */
    int num_sats;
    int sol_type;
    int status;     /** 0: invalid, 1: valid */
} gi_gnss_t;

typedef struct gi_out_t
{
    double timestamp;
    double blh[3];          /** blh: latitude, longitude, height */
    double euler[3];        /** euler: roll, pitch, yaw */
    double velo;            /** velocity with sign, positive for moving forward */
    double accel;           /** acceleration with sign, positive for moving forward */
    double angle_rate;      /** angle_rate: yaw angular rate in deg/s */
    double pos_cov[3];      /** pos_cov: position covariance */
    double euler_cov[3];    /** euler_cov: euler angle covariance */
    double vel_cov;         /** vel_cov: velocity covariance */
    double accel_cov;       /** accel_cov: acceleration covariance */
    double angle_rate_cov;  /** angle_rate_cov: yaw angular rate covariance */
    int status;             /** 0: invalid, 1: valid */
} gi_out_t;


class GIFusion; /** forward declaration */

class GIFusionInterface {
public:
    GIFusionInterface();
    ~GIFusionInterface();

    status_e process_gnss_data(const gi_gnss_t& gnss_data);
    status_e process_imu_data(const gi_imu_t& imu_data);
    status_e get_output(const double timestamp, gi_out_t& output);

private:
    std::unique_ptr<GIFusion> pimpl;  // 使用智能指针管理实现类
};

#endif // GIFUSION_INTERFACE_H