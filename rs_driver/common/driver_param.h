/******************************************************************************
 * Copyright 2020 RoboSense All rights reserved.
 * Suteng Innovation Technology Co., Ltd. www.robosense.ai

 * This software is provided to you directly by RoboSense and might
 * only be used to access RoboSense LiDAR. Any compilation,
 * modification, exploration, reproduction and redistribution are
 * restricted without RoboSense's prior consent.

 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOSENSE BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
#pragma once
#include <string>

namespace robosense
{

    namespace lidar
    {

        enum class LiDAR_TYPE ///< The lidar type
        {
            RS16,
            RS32,
            RSBP,
            RS128
        };
        typedef struct RSDecoder_Param ///< The lidar decoder parameter
        {
            float max_distance = 200.0f;   ///< The max distance of lidar detect range
            float min_distance = 0.2f;     ///< The minimum distance of lidar detect range
            float start_angle = 0.0f;      ///< The start angle of point cloud
            float end_angle = 360.0f;      ///< The end angle of point cloud
            uint16_t mode_split_frame = 1; ///< 1: Split frame depends on cut_angle; 2:Split frame depends on packet rate; 3:Split frame depends on num_pkts_split
            uint32_t num_pkts_split = 0;   ///< The number of packets in one frame, only be used when mode_split_frame=3
            float cut_angle = 0.0f;        ///< The cut angle used to split frame, only be used when mode_split_frame=1
            void print() const             ///< This function is used to print all the parameters for debug
            {
                std::cout << "\033[1m\033[32m"
                          << "------------------------------------------------------"
                          << "\033[0m" << std::endl;
                std::cout << "\033[1m\033[32m"
                          << "             Robosense Decoder Parameters "
                          << "\033[0m" << std::endl;
                std::cout << "\033[32m"
                          << "max_distance : " << max_distance << std::endl;
                std::cout << "min_distance : " << min_distance << std::endl;
                std::cout << "start_angle : " << start_angle << std::endl;
                std::cout << "end_angle : " << end_angle << std::endl;
                std::cout << "mode_split_frame : " << mode_split_frame << std::endl;
                std::cout << "num_pkts_split : " << num_pkts_split << std::endl;
                std::cout << "cut_angle : " << cut_angle << "\033[0m" << std::endl;
                std::cout << "\033[1m\033[32m"
                          << "------------------------------------------------------"
                          << "\033[0m" << std::endl;
            }
        } RSDecoder_Param;

        typedef struct RSInput_Param ///< The lidar input parameter
        {
            std::string device_ip = "192.168.1.200"; ///< The ip of lidar
            uint16_t msop_port = 6699;               ///< The msop packet port number
            uint16_t difop_port = 7788;              ///< The difop packet port number
            bool read_pcap = false;                  ///< True: The driver will process the pcap through pcap_file_dir. False: The driver will get data from online lidar
            bool pcap_repeat = false;                ///< True: The pcap bag will repeat play
            std::string pcap_file_dir = "null";      ///< The absolute path of pcap file
            void print() const                       ///< This function is used to print all the parameters for debug
            {
                std::cout << "\033[1m\033[32m"
                          << "------------------------------------------------------"
                          << "\033[0m" << std::endl;
                std::cout << "\033[1m\033[32m"
                          << "             Robosense Input Parameters "
                          << "\033[0m" << std::endl;
                std::cout << "\033[32m"
                          << "device_ip : " << device_ip << std::endl;
                std::cout << "msop_port : " << msop_port << std::endl;
                std::cout << "difop_port : " << difop_port << std::endl;
                std::cout << "read_pcap : " << read_pcap << std::endl;
                std::cout << "pcap_repeat : " << pcap_repeat << std::endl;
                std::cout << "pcap_file_dir : " << pcap_file_dir << "\033[0m" << std::endl;
                std::cout << "\033[1m\033[32m"
                          << "------------------------------------------------------"
                          << "\033[0m" << std::endl;
            }
        } RSInput_Param;

        typedef struct RSLiDAR_Driver_Param ///< The lidar driver parameter
        {
            RSInput_Param input_param;                ///< The input parameter
            RSDecoder_Param decoder_param;            ///< The decoder parameter
            std::string angle_path = "null";          ///< The path of angle calibration files(angle.csv)(for latest version lidar, this file is not needed)
            std::string frame_id = "rslidar";         ///< The frame id of lidar message
            LiDAR_TYPE lidar_type = LiDAR_TYPE::RS16; ///< Lidar type
            bool use_lidar_clock = false;             ///< True: lidar message timestamp is the lidar clock. False: timestamp is the computer system clock
            void print() const                        ///< This function is used to print all the parameters for debug
            {
                input_param.print();
                decoder_param.print();
                std::cout << "\033[1m\033[32m"
                          << "------------------------------------------------------"
                          << "\033[0m" << std::endl;
                std::cout << "\033[1m\033[32m"
                          << "             Robosense Driver Parameters "
                          << "\033[0m" << std::endl;
                std::cout << "\033[32m"
                          << "angle_path : " << angle_path << std::endl;
                std::cout << "frame_id : " << frame_id << std::endl;
                std::cout << "use_lidar_clock : " << use_lidar_clock << std::endl;

                switch (lidar_type)
                {
                case LiDAR_TYPE::RS16:
                    std::cout << "lidar_type : "
                              << "\033[0m";
                    std::cout << "\033[1m\033[32m"
                              << "RS16"
                              << "\033[0m" << std::endl;
                    break;
                case LiDAR_TYPE::RS32:
                    std::cout << "lidar_type : "
                              << "\033[0m";
                    std::cout << "\033[1m\033[32m"
                              << "RS32"
                              << "\033[0m" << std::endl;
                    break;
                case LiDAR_TYPE::RSBP:
                    std::cout << "lidar_type : "
                              << "\033[0m";
                    std::cout << "\033[1m\033[32m"
                              << "RSBP"
                              << "\033[0m" << std::endl;
                    break;
                case LiDAR_TYPE::RS128:
                    std::cout << "lidar_type : "
                              << "\033[0m";
                    std::cout << "\033[1m\033[32m"
                              << "RS128"
                              << "\033[0m" << std::endl;
                    break;
                default:
                    std::cout << "lidar_type : "
                              << "\033[0m";
                    std::cout << "\033[1m\033[31m"
                              << "ERROR"
                              << "\033[0m" << std::endl;
                    break;
                }

                std::cout << "\033[1m\033[32m"
                          << "------------------------------------------------------"
                          << "\033[0m" << std::endl;
            }
        } RSLiDAR_Driver_Param;
    } // namespace lidar
} // namespace robosense