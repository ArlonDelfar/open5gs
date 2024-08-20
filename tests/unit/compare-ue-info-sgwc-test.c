#include "abts.h"
#include "mme-context.h"
#include "context.h"
#include "pfcp/context.h"
#include "src/sgwc/context.h"
#include "src/smf/context.h"

static bool compare_ue_info(ogs_pfcp_node_t *node, sgwc_sess_t *sess);

void test_compare_ue_info(abts_case *tc, void *data)
{
    ogs_pfcp_node_t node = {
        .num_of_dnn = 2,
        .dnn = {"internet", "intranet"},
        .num_of_e_cell_id = 2,
        .e_cell_id = {201, 202},
        .num_of_tac = 2,
        .tac = {101, 102}
    };

        sgwc_sess_t sess = {
        .sgwc_ue_id = 1,
        .session.name = "internet"
    };
    ABTS_TRUE(tc, compare_ue_info(&node, &sess));
}