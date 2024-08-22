#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <pthread.h>
#include <math.h>

const char *OGS_FSM_NAME_INIT_SIG = "OGS_FSM_NAME_INIT_SIG";
const char *OGS_FSM_NAME_ENTRY_SIG = "OGS_FSM_NAME_ENTRY_SIG";
const char *OGS_FSM_NAME_EXIT_SIG = "OGS_FSM_NAME_EXIT_SIG";


typedef enum {
	OGS_FSM_ENTRY_SIG,
	OGS_FSM_EXIT_SIG
} KK; 




const char *smf_event_get_name(const char *tab_in)
{
	
	if (tab_in == NULL) {
        return "OGS_FSM_NAME_INIT_SIG";
    }

    switch (*tab_in) {

    case OGS_FSM_ENTRY_SIG:
        return "OGS_FSM_NAME_ENTRY_SIG";
    case OGS_FSM_EXIT_SIG:
        return "OGS_FSM_NAME_EXIT_SIG";

/*    case SMF_EVT_S5C_MESSAGE:
        return "SMF_EVT_S5C_MESSAGE";
    case SMF_EVT_S6B_MESSAGE:
        return "SMF_EVT_S6B_MESSAGE";
    case SMF_EVT_GN_MESSAGE:
        return "SMF_EVT_GN_MESSAGE";
    case SMF_EVT_GX_MESSAGE:
        return "SMF_EVT_GX_MESSAGE";
    case SMF_EVT_GY_MESSAGE:
        return "SMF_EVT_GY_MESSAGE";
    case SMF_EVT_N4_MESSAGE:
        return "SMF_EVT_N4_MESSAGE";
    case SMF_EVT_N4_TIMER:
        return "SMF_EVT_N4_TIMER";
    case SMF_EVT_N4_NO_HEARTBEAT:
        return "SMF_EVT_N4_NO_HEARTBEAT";

    case OGS_EVENT_SBI_SERVER:
        return OGS_EVENT_NAME_SBI_SERVER;
    case OGS_EVENT_SBI_CLIENT:
        return OGS_EVENT_NAME_SBI_CLIENT;
    case OGS_EVENT_SBI_TIMER:
        return OGS_EVENT_NAME_SBI_TIMER;

    case SMF_EVT_NGAP_MESSAGE:
        return "SMF_EVT_NGAP_MESSAGE";
    case SMF_EVT_NGAP_TIMER:
        return "SMF_EVT_NGAP_TIMER";

    case SMF_EVT_5GSM_MESSAGE:
        return "SMF_EVT_5GSM_MESSAGE";
    case SMF_EVT_5GSM_TIMER:
        return "SMF_EVT_5GSM_TIMER";
*/
//    default:
 //      break;
       
    }

/*
    ogs_error("Unknown Event[%d]", e->h.id);
    return "UNKNOWN_EVENT";
*/    
}

int main(){

const char* tab[2][3];
tab[0][0]=NULL;
tab[1][0]="OGS_FSM_NAME_INIT_SIG";
tab[0][1]="OGS_FSM_ENTRY_SIG";
tab[1][1]="OGS_FSM_NAME_ENTRY_SIG";
tab[0][2]="OGS_FSM_EXIT_SIG";
tab[1][2]="OGS_FSM_NAME_EXIT_SIG";


int Lok=0, Lwr=0, c=0;

for(int i=0; i<2; i++){

	const char* tab_in = tab[0][i];
	const char* tab_control = tab[1][i];
	const char* tab_out = smf_event_get_name(tab_in);
	
	printf("\ntab_in %s", tab_in);
	printf("\ntab_control %s", tab_control);
	printf("\ntab_out %s", tab_out);
	
	
	c++;
	if(strcmp(tab_control, tab_out)==0){
		Lok++;
		printf("\nUNIT TEST #%d OK", c);
	} 
	if(strcmp(tab_control, tab_out)!=0) {
		printf("\nUNIT TEST #%d WRONG", c);
	}
	
}

double cp, Lok2, c2;
c2=c;
Lok2=Lok;
cp=100*Lok2/c2;

printf("\n\nFINISHED\n%.1f%% (%.f/%.f) UNIT TESTS OK", cp, Lok2, c2);

	
	
return 0;
}
