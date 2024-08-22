#include "core/abts.h"
#include "smf/timer.h"

static void test_valid_timer_ids(abts_case *tc, void *data)
{
    abts_assert_str_equal(tc, "OGS_TIMER_NAME_NF_INSTANCE_REGISTRATION_INTERVAL", smf_timer_get_name(OGS_TIMER_NF_INSTANCE_REGISTRATION_INTERVAL));
    abts_assert_str_equal(tc, "OGS_TIMER_NAME_NF_INSTANCE_HEARTBEAT_INTERVAL", smf_timer_get_name(OGS_TIMER_NF_INSTANCE_HEARTBEAT_INTERVAL));
    abts_assert_str_equal(tc, "OGS_TIMER_NAME_NF_INSTANCE_NO_HEARTBEAT", smf_timer_get_name(OGS_TIMER_NF_INSTANCE_NO_HEARTBEAT));
    abts_assert_str_equal(tc, "OGS_TIMER_NAME_NF_INSTANCE_VALIDITY", smf_timer_get_name(OGS_TIMER_NF_INSTANCE_VALIDITY));
    abts_assert_str_equal(tc, "OGS_TIMER_NAME_SUBSCRIPTION_VALIDITY", smf_timer_get_name(OGS_TIMER_SUBSCRIPTION_VALIDITY));
    abts_assert_str_equal(tc, "OGS_TIMER_NAME_SUBSCRIPTION_PATCH", smf_timer_get_name(OGS_TIMER_SUBSCRIPTION_PATCH));
    abts_assert_str_equal(tc, "OGS_TIMER_NAME_SBI_CLIENT_WAIT", smf_timer_get_name(OGS_TIMER_SBI_CLIENT_WAIT));
    abts_assert_str_equal(tc, "SMF_TIMER_PFCP_ASSOCIATION", smf_timer_get_name(SMF_TIMER_PFCP_ASSOCIATION));
    abts_assert_str_equal(tc, "SMF_TIMER_PFCP_NO_HEARTBEAT", smf_timer_get_name(SMF_TIMER_PFCP_NO_HEARTBEAT));
    abts_assert_str_equal(tc, "SMF_TIMER_PFCP_NO_ESTABLISHMENT_RESPONSE", smf_timer_get_name(SMF_TIMER_PFCP_NO_ESTABLISHMENT_RESPONSE));
    abts_assert_str_equal(tc, "SMF_TIMER_PFCP_NO_DELETION_RESPONSE", smf_timer_get_name(SMF_TIMER_PFCP_NO_DELETION_RESPONSE));
}

static void test_invalid_timer_id(abts_case *tc, void *data)
{
    abts_assert_str_equal(tc, "UNKNOWN_TIMER", smf_timer_get_name(-1));
    abts_assert_str_equal(tc, "UNKNOWN_TIMER", smf_timer_get_name(MAX_NUM_OF_SMF_TIMER));
}

abts_suite *test_timer(abts_suite *suite)
{
    suite = ADD_SUITE(suite);

    abts_run_test(suite, test_valid_timer_ids, NULL);
    abts_run_test(suite, test_invalid_timer_id, NULL);

    return suite;
}
