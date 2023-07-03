#pragma once

#include "stdint.h"
typedef enum
{
    // MSG FROM NEXTION RX TO MAIN TASK
    HOME_LOADED,
    HOME_TARA_1_ENABLED,
    HOME_TARA_1_DISABLED,
    HOME_TARA_2_ENABLED,
    HOME_TARA_2_DISABLED,
    HOME_TARA_3_ENABLED,
    HOME_TARA_3_DISABLED,
    HOME_TARA_4_ENABLED,
    HOME_TARA_4_DISABLED,
    SYSTEM_SETTINGS_LOADED,
    CALIBRATION_LOADED,
    CALIBRATION_SWITCH_1_ENABLED,
    CALIBRATION_SWITCH_1_DISABLED,
    CALIBRATION_SWITCH_2_ENABLED,
    CALIBRATION_SWITCH_2_DISABLED,
    CALIBRATION_SWITCH_3_ENABLED,
    CALIBRATION_SWITCH_3_DISABLED,
    CALIBRATION_SWITCH_4_ENABLED,
    CALIBRATION_SWITCH_4_DISABLED,
    CALIBRATION_SWITCH_5_ENABLED,
    CALIBRATION_SWITCH_5_DISABLED,
    CALIBRATION_SWITCH_6_ENABLED,
    CALIBRATION_SWITCH_6_DISABLED,
    CALIBRATION_SWITCH_7_ENABLED,
    CALIBRATION_SWITCH_7_DISABLED,
    CALIBRATION_SWITCH_8_ENABLED,
    CALIBRATION_SWITCH_8_DISABLED,
    INPUTCALIBP1_LOADED,
    INPUTCALIBP1_TYPE_RECEIVED,
    INPUTCALIBP1_CAPACITY_RECEIVED,
    INPUTCALIBP1_CAPACITY_UNIT_RECEIVED,
    INPUTCALIBP1_SENSIBILITY_RECEIVED,
    INPUTCALIBP1_SENSIBILITY_UNIT_RECEIVED,
    INPUTCALIBP1_SENSOR_INDEX_RECEIVED,
    INPUTCALIBP2_LOADED,
    INPUTCALIBP2_CALIBRATION_LIMIT_RECEIVED,
    INPUTCALIBP2_CALIBRATION_LIMIT_UNIT_RECEIVED,
    INPUTCALIBP2_LIMIT_ENABLE_RECEIVED,
    INPUTCALIBP3_LOADED,
    INPUTCALIBP3_TABLE_RECEIVED,
    INPUTCALIBP3_NUM_POINTS_RECEIVED,
    INPUTCALIBP3_ROW_TO_FILL_RECEIVED,
    INPUTCALIBP4_LOADED,
    INPUTCALIBP4_NAME_RECEIVED,
    INPUTCALIBP4_SAVE_PRESSED,

    EXTERNAL_SENSOR_5_UNIT_CHANGED,
    EXTERNAL_SENSOR_6_UNIT_CHANGED,
    EXTERNAL_SENSOR_7_UNIT_CHANGED,
    EXTERNAL_SENSOR_8_UNIT_CHANGED,
    EXTERNAL_SENSOR_5_UNITPS_CHANGED,
    EXTERNAL_SENSOR_6_UNITPS_CHANGED,
    EXTERNAL_SENSOR_7_UNITPS_CHANGED,
    EXTERNAL_SENSOR_8_UNITPS_CHANGED,

    //
    NEXTION_UPDATE,

} msg_type_t;

typedef enum
{
    HOME = 0,
    SYSTEM_SETTINGS,
    CALIBRATION,
    INPUTCALIBP1,
    INPUTCALIBP2,
    INPUTCALIBP3,
    INPUTCALIBP4,

} page_t;

typedef struct
{
    page_t page;
} page_status_t;

typedef struct
{
    msg_type_t type;
    union
    {
        uint32_t u32;
        float f32;
        int32_t i32;
        void *addr;
    } content;
    int size;
} msg_t;

typedef enum
{
    DISPLACEMENT,
    LOAD,
    PRESSURE,
    VOLUME,
    SENSOR_TYPE_MAX,
} sensor_type_t;
typedef enum
{
    DISPLACEMENT_UNIT_CM,
    DISPLACEMENT_UNIT_IN,
    DISPLACEMENT_UNIT_MM,
    DISPLACEMENT_UNIT_MAX,
} sensor_displacement_unit_t;
typedef enum
{
    LOAD_UNIT_KN,
    LOAD_UNIT_LBF,
    LOAD_UNIT_N,
    LOAD_UNIT_KGF,
    LOAD_UNIT_MAX,
} sensor_load_unit_t;
typedef enum
{
    PRESSURE_UNIT_KPA,
    PRESSURE_UNIT_PSI,
    PRESSURE_UNIT_KSF,
    PRESSURE_UNIT_MPA,
    PRESSURE_UNIT_KGF_CM2,
    PRESSURE_UNIT_MAX,
} sensor_pressure_unit_t;
typedef enum
{
    VOLUME_UNIT_CM3,
    VOLUME_UNIT_IN3,
    VOLUME_UNIT_MAX,
} sensor_volume_unit_t;
typedef union
{
    sensor_displacement_unit_t displacement_unit;
    sensor_load_unit_t load_unit;
    sensor_pressure_unit_t pressure_unit;
    sensor_volume_unit_t volume_unit;
} sensor_data_unit_t;
typedef enum
{
    SENSIBILITY_UNIT_MV_V,
    SENSIBILITY_UNIT_V_V,
    SENSIBILITY_UNIT_MAX,
} sensor_sensibility_unit_t;
