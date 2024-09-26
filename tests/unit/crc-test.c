#include "crc/crc.h" 
#include "core/abts.h"
#include "crc/metrics.h"

static void crc_metrics_example(abts_case *tc, void *data){

    uint8_t poly = 0b10100000;
    uint8_t buffor[] = { 0b11010110 };

    crc_metrics_inst_global_inc(CRC_METR_GLOB_CTR_NUM);
    uint8_t crc_value = crc(buffor, sizeof(buffor),poly);

    uint8_t buffor2[sizeof(buffor) + 1];
    memcpy(buffor2, buffor, sizeof(buffor));
    buffor2[sizeof(buffor)] = crc_value;

    crc_metrics_inst_global_inc(CRC_METR_GLOB_CTR_NUM);
    crc_value = crc(buffor2, sizeof(buffor2),poly);
    if(crc_value == 0){
        crc_metrics_inst_global_inc(CRC_METR_GLOB_CTR_FAIL);
    }
    ABTS_INT_EQUAL(tc, 0, crc_value);
}

static void crc_test_succes(abts_case *tc, void *data) {
    uint8_t poly = 0b10100000;
    uint8_t buffor[] = { 0b11010110 };
    uint8_t crc_value = crc(buffor, sizeof(buffor),poly);

    uint8_t buffor2[sizeof(buffor) + 1];
    memcpy(buffor2, buffor, sizeof(buffor));
    buffor2[sizeof(buffor)] = crc_value;

    crc_value = crc(buffor2, sizeof(buffor2),poly);
    ABTS_INT_EQUAL(tc, 0, crc_value);
}

static void crc_test_failure(abts_case *tc, void *data) {
    uint8_t poly = 0b10100000;
    uint8_t buffor[] = { 0b11010110 };
    uint8_t crc_value = crc(buffor, sizeof(buffor),poly);

    uint8_t buffor2[sizeof(buffor) + 1];
    memcpy(buffor2, buffor, sizeof(buffor));
    buffor2[sizeof(buffor)] = crc_value;

    buffor2[0] += 1; //błąd;

    crc_value = crc(buffor2, sizeof(buffor2),poly);
    ABTS_INT_NEQUAL(tc, 0, crc_value);
}

abts_suite *test_crc(abts_suite *suite)
{
    suite = ADD_SUITE(suite)
    abts_run_test(suite, crc_test_failure, NULL);
    abts_run_test(suite, crc_test_succes, NULL);
    abts_run_test(suite, crc_metrics_example, NULL);
    return suite;
}



