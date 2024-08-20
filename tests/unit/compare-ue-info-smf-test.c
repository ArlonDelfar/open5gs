#include "abts.h"
#include "mme-context.h"
#include "context.h"
#include "pfcp/context.h"
#include "src/sgwc/context.h"
#include "src/smf/context.h"

static bool compare_ue_info(ogs_pfcp_node_t *node, smf_sess_t *sess);

void test_compare_ue_info(abts_case *tc, void *data)
{
    ogs_pfcp_node_t node = {
        .num_of_dnn = 2,
        .dnn = {"internet", "intranet"},
        .num_of_e_cell_id = 2,
        .e_cell_id = {201, 202},
        .num_of_nr_cell_id = 2,
        .nr_cell_id = {301, 302},
        .num_of_tac = 2,
        .tac = {101, 102}
    };

    smf_sess_t sess1 = {
        .session = {.name = "internet"},
        .gtp_rat_type = OGS_GTP2_RAT_TYPE_EUTRAN
    };
    ABTS_TRUE(tc, compare_ue_info(&node, &sess1));

    smf_sess_t sess2 = {
        .session = {.name = "not_matching"},
        .gtp_rat_type = OGS_GTP2_RAT_TYPE_EUTRAN,
        .e_cgi = {.cell_id = 202}
    };
    ABTS_TRUE(tc, compare_ue_info(&node, &sess2));

    smf_sess_t sess3 = {
        .session = {.name = "not_matching"},
        .nr_cgi = {.cell_id = 302}
    };
    ABTS_TRUE(tc, compare_ue_info(&node, &sess3));

    smf_sess_t sess4 = {
        .session = {.name = "not_matching"},
        .gtp_rat_type = OGS_GTP2_RAT_TYPE_EUTRAN,
        .e_tai = {.tac = 102}
    };
    ABTS_TRUE(tc, compare_ue_info(&node, &sess4));

    smf_sess_t sess5 = {
        .session = {.name = "not_matching"},
        .nr_tai = {.tac.v = 102}
    };
    ABTS_TRUE(tc, compare_ue_info(&node, &sess5));

    smf_sess_t sess6 = {
        .session = {.name = "not_matching"},
        .gtp_rat_type = OGS_GTP2_RAT_TYPE_EUTRAN,
        .e_cgi = {.cell_id = 999},
        .e_tai = {.tac = 999},
        .nr_cgi = {.cell_id = 999},
        .nr_tai = {.tac.v = 999}
    };
    ABTS_FALSE(tc, compare_ue_info(&node, &sess6));
}