#ifndef _INC_DEFINE_H_
#define _INC_DEFINE_H_

// 纬度半球
typedef emun {
    LATITUDE_HEM_N = 0,         // 北纬
    LATITUDE_HEM_S              // 南纬
} latitude_hem_e;

// 纬度半球
typedef emun {
    LONGITUDE_HEM_E = 0,        // 东经
    LONGITUDE_HEM_W             // 西经
} longitude_hem_e;

// GPS 状态
typedef emun {
    GPS_UNTARGETED = 0,         // 未定位
    GPS_NON_DIFFERENTIAL,       // 非差分定位
    GPS_DIFFERENTIAL            // 差分定位
} gps_status_e;

// GPGSA模式
typedef emun {
    GPGSA_MODE_M = 0,           // 手动
    GPGSA_MODE_A                // 自动
} gpgsa_mode_e;

// GPGSA定位类型
typedef emun {
    GPGSA_UNTARGETED = 0,       // 未定位
    GPGSA_2D_POS,               // 2D 定位
    GPGSA_3D_POS                // 3D 定位
} gpgsa_type_e;

// GPRMC定位状态
typedef emun {
    GPRMC_EFFECTIVE = 0,        // 有效定位
    GPRMC_INVALID               // 无效定位
} gprmc_status_e;

// 磁偏角方向
typedef emun {
    GPRMC_MD_E = 0,             // E(东)
    GPRMC_MD_W                  // W(西)
} gprmc_md_dire_e;

// 模式指示
typedef emun {
    GPRMC_IND_AUTO = 0,         // 自主定位
    GPRMC_IND_DIFF,             // 差分
    GPRMC_IND_EST,              // 估算
    GPRMC_IND_INVALID           // 数据无效
} gprmc_mode_ind_e;

// 全球定位数据
typedef struct {
                                                    // UTC 时间，格式为 hhmmss.sss
    DOUBLE              md_latitude;                // 纬度，格式为 ddmm.mmmmm(度分格式)
    latitude_hem_e      me_latitude_hem;            // 纬度半球
    DOUBLE              md_longitude;               // 经度，格式为 dddmm.mmmmm(度分格式)
    longitude_hem_e     me_longitude_hem;           // 经度半球
    gps_status_e        me_gps_status;              // GPS 状态
    INT8U               mu_sate_cnt;                // 正在使用的用于定位的卫星数量
    DOUBLE              md_hdop;                    // 水平精确度因子(0.5~99.9)
    DOUBLE              md_altitude;                // 海拔高度(-9999.9 到 9999.9米)
    DOUBLE              md_geoid;                   // 大地水准面高度(-9999.9 到 9999.9米)
    INT32U              m32_diff_time;              // 差分时间(从最近一次接收到差分信号开始的秒数，非差分定位，此项为空)
    INT32U              m32_station_label;          // 差分参考基站标号(0000 到 1023，非差分定位，此项为空)
} gnss_gpgga_t;

// 卫星PRN数据
typedef struct {
    gpgsa_mode_e        me_mode;                    // GPGSA模式
    gpgsa_type_e        me_type;                    // GPGSA定位类型
    INT8U               mu8_sate_label;             // 正在用于定位的卫星号(01~32)
    INT8U               mu8_prn[12];                // 第1-12信道正在使用的卫星PRN码编号，01至32
    DOUBLE              md_pdop;                    // PDOP 综合位置精度因子(0.5-99.9)
    DOUBLE              md_hdop;                    // HDOP 水平精度因子(0.5-99.9)
    DOUBLE              md_vdop;                    // VDOP 垂直精度因子(0.5-99.9)
} gnss_gpgsa_t;

// 推荐定位信息
typedef struct {
                                                    // UTC 时间，hhmmss(时分秒)
    gprmc_status_e      me_status;                  // 定位状态
    DOUBLE              md_latitude;                // 纬度 ddmm.mmmmm(度分)
    latitude_hem_e      me_latitude_hem;            // 纬度半球
    DOUBLE              md_longitude;               // 经度 dddmm.mmmmm(度分)
    longitude_hem_e     me_longitude_hem;           // 经度半球
    DOUBLE              md_rate;                    // 地面速率(000.0~999.9 节)
    DOUBLE              md_course;                  // 地面航向(000.0~359.9 度，以真北方为参考基准)
                                                    // UTC 日期，ddmmyy(日月年)
    DOUBLE              md_md;                      // 磁偏角(000.0~180.0 度，前导位数不足则补 0)
    gprmc_md_dire_e     me_md_dire;                 // 磁偏角方向
    gprmc_mode_ind_e    me_mode;                    // 模式指示
} gnss_gprmc_t;

// 地面速度信息
typedef struct {
    INT32U              md_course;                  // 以真北为参考基准的地面航向(000~359度)
    INT32U              md_course_md;               // 以磁北为参考基准的地面航向(000~359度)
    DOUBLE              md_rate;                    // 地面速率(000.0~999.9节)
    DOUBLE              md_speed;                   // 地面速率(0000.0~1851.8公里/小时)
    gprmc_mode_ind_e    me_mode;                    // 模式指示(A=自主定位，D=差分，E=估算，N=数据无效)
} gnss_gpvtg_t;

#endif /* _INC_DEFINE_H_ */