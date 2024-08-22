#include "core/abts.h"
#include "ogs-core.h"
#include "smf/context.h"


static void smf_bearer_add_test_psi(abts_case *tc, void *data)
{
    smf_context_init();

    smf_ue_t *ue = smf_ue_add_by_imsi("1", 1);
    ABTS_PTR_NOTNULL(tc, ue);

    smf_sess_t *sess = smf_sess_add_by_psi(ue, 123);
    ABTS_PTR_NOTNULL(tc, sess);
    sess->session.session_type = OGS_PDU_SESSION_TYPE_IPV4;
    
    smf_bearer_t *bearer  = smf_bearer_add(sess);
    ABTS_PTR_NOTNULL(tc, bearer);

    ABTS_PTR_NOTNULL(tc, bearer->dl_pdr);
    ABTS_PTR_NOTNULL(tc, bearer->ul_pdr);
    ABTS_PTR_NOTNULL(tc, bearer->dl_far);
    ABTS_PTR_NOTNULL(tc, bearer->ul_far);

    ABTS_INT_EQUAL(tc, bearer->sess_id, sess->id);
    ABTS_INT_EQUAL(tc, bearer->ul_pdr->outer_header_removal.description, OGS_PFCP_OUTER_HEADER_REMOVAL_GTPU_UDP_IPV4);

    smf_context_final();
}



abts_suite *test_smf_bearer_add(abts_suite *suite)
{
    suite = ADD_SUITE(suite)

    abts_run_test(suite, smf_bearer_add_test_psi, NULL);

    return suite;
}