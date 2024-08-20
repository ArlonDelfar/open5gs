#include "abts.h"
#include "mme-context.h"
#include "context.h"
#include "pfcp/context.h"
#include "src/sgwc/context.h"
#include "src/smf/context.h"

static bool compare_ue_info(mme_sgw_t *node, enb_ue_t *enb_ue);

void test_compare_ue_info(abts_case *tc, void *data)
{
    mme_sgw_t node = {
        .num_of_tac = 3,
        .tac = {101, 102, 103},
        .num_of_e_cell_id = 3,
        .e_cell_id = {201, 202, 203}
    };

    enb_ue_t enb_ue_1 = {.saved.tai.tac = 102, .saved.e_cgi.cell_id = 0};
    enb_ue_t enb_ue_2 = {.saved.tai.tac = 0, .saved.e_cgi.cell_id = 202};
    enb_ue_t enb_ue_3 = {.saved.tai.tac = 104, .saved.e_cgi.cell_id = 204};

    ABTS_TRUE(tc, compare_ue_info(&node, &enb_ue_1));
    ABTS_TRUE(tc, compare_ue_info(&node, &enb_ue_2));
    ABTS_FALSE(tc, compare_ue_info(&node, &enb_ue_3));
}