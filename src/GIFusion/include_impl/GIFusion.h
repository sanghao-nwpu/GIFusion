#include <iostream>
#include <Eigen/Dense>
#include "GIFusionInterface.h"




class GIFusion
{
    public:
        GIFusion() {}
        virtual ~GIFusion() {}
        status_e process_gnss_data(const gi_gnss_t& gnss_data);
        status_e process_imu_data(const gi_imu_t& imu_data);
        status_e get_output(const double timestamp, gi_out_t& output);

    private:
        Eigen::Vector3d blh_;
};

GIFusionInterface::GIFusionInterface()
{
    std::cout << "GIFusionInterface constructor called." << std::endl;
    pimpl = std::make_unique<GIFusion>();
}

status_e GIFusionInterface::process_gnss_data(const gi_gnss_t& gnss_data)
{
    std::cout << "process_gnss_data called." << std::endl;
    return pimpl->process_gnss_data(gnss_data);
}

status_e GIFusionInterface::process_imu_data(const gi_imu_t& imu_data)
{
    std::cout << "process_imu_data called." << std::endl;
    return pimpl->process_imu_data(imu_data);
}


status_e GIFusionInterface::get_output(const double timestamp, gi_out_t& output)
{    
    std::cout << "get_output called." << std::endl;
    return pimpl->get_output(timestamp, output);
}