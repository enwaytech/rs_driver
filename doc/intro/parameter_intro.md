# Parameters Introduction

#### 1. RSDecoder_Param
```c++
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
} RSDecoder_Param;
```



#### 2. RSInput_Param

```c++
typedef struct RSInput_Param ///< The lidar input parameter
{
    std::string device_ip = "192.168.1.200"; ///< The ip of lidar
    uint16_t msop_port = 6699;               ///< The msop packet port number
    uint16_t difop_port = 7788;              ///< The difop packet port number
    bool read_pcap = false;                  ///< True: The driver will process the pcap through pcap_file_dir. False: The driver will get data from online lidar
    bool pcap_repeat = false;                ///< True: The pcap bag will repeat play
    std::string pcap_file_dir = "null";      ///< The absolute path of pcap file
    void print() const                       ///< This function is used to print all the parameters for debug
} RSInput_Param;
```




#### 3. RSLiDAR_Driver_Param
```c++
typedef struct RSLiDAR_Driver_Param ///< The lidar driver parameter
{
    RSInput_Param input_param;                ///< The input parameter
    RSDecoder_Param decoder_param;            ///< The decoder parameter
    std::string angle_path = "null";          ///< The path of angle calibration files(angle.csv)(for latest version lidar, this file is not needed)
    std::string frame_id = "rslidar";         ///< The frame id of lidar message
    LiDAR_TYPE lidar_type = LiDAR_TYPE::RS16; ///< Lidar type
    bool use_lidar_clock = false;             ///< True: lidar message timestamp is the lidar clock. False: timestamp is the computer system clock
    void print() const                        ///< This function is used to print all the parameters for debug
} RSLiDAR_Driver_Param;
```


