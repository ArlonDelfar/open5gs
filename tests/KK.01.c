#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <pthread.h>
#include <math.h>

	const char *OGS_FSM_NAME_INIT_SIG = "OGS_FSM_NAME_INIT_SIG"; //out
	const char *OGS_FSM_NAME_ENTRY_SIG = "OGS_FSM_NAME_ENTRY_SIG";
	const char *OGS_FSM_NAME_EXIT_SIG = "OGS_FSM_NAME_EXIT_SIG";
	const char *SMF_EVT_S5C_MESSAGE = "SMF_EVT_S5C_MESSAGE";
	const char *SMF_EVT_S6B_MESSAGE = "SMF_EVT_S6B_MESSAGE";
	const char *SMF_EVT_GN_MESSAGE = "SMF_EVT_GN_MESSAGE";
	const char *SMF_EVT_GX_MESSAGE = "SMF_EVT_GX_MESSAGE";
	const char *SMF_EVT_GY_MESSAGE = "SMF_EVT_GY_MESSAGE";
	const char *SMF_EVT_N4_MESSAGE = "SMF_EVT_N4_MESSAGE";
	const char *SMF_EVT_N4_TIMER = "SMF_EVT_N4_TIMER";
	const char *SMF_EVT_N4_NO_HEARTBEAT = "SMF_EVT_N4_NO_HEARTBEAT";
	const char *OGS_EVENT_NAME_SBI_SERVER = "OGS_EVENT_NAME_SBI_SERVER";
	const char *OGS_EVENT_NAME_SBI_CLIENT = "OGS_EVENT_NAME_SBI_CLIENT";
	const char *OGS_EVENT_NAME_SBI_TIMER = "OGS_EVENT_NAME_SBI_TIMER";
	const char *SMF_EVT_NGAP_MESSAGE = "SMF_EVT_NGAP_MESSAGE";
	const char *SMF_EVT_NGAP_TIMER = "SMF_EVT_NGAP_TIMER";
	const char *SMF_EVT_5GSM_MESSAGE = "SMF_EVT_5GSM_MESSAGE";
	const char *SMF_EVT_5GSM_TIMER = "SMF_EVT_5GSM_TIMER";
	
	typedef enum {  
	    OGS_FSM_ENTRY_SIG,
	    OGS_FSM_EXIT_SIG,
	    _SMF_EVT_S5C_MESSAGE,
	    _SMF_EVT_S6B_MESSAGE,
	    _SMF_EVT_GN_MESSAGE,
		_SMF_EVT_GX_MESSAGE,
		_SMF_EVT_GY_MESSAGE,
		_SMF_EVT_N4_MESSAGE,
		_SMF_EVT_N4_TIMER,
		_SMF_EVT_N4_NO_HEARTBEAT,
		OGS_EVENT_SBI_SERVER,
	    OGS_EVENT_SBI_CLIENT,
	    OGS_EVENT_SBI_TIMER,
	    _SMF_EVT_NGAP_MESSAGE,
	    _SMF_EVT_NGAP_TIMER,
	    _SMF_EVT_5GSM_MESSAGE,
	    _SMF_EVT_5GSM_TIMER
	    
	}KKin;
		
	const char *smf_event_get_name(const char *tab_in, int j)
	{
		
		if (tab_in == NULL) {
			return "OGS_FSM_NAME_INIT_SIG";
		}
		
		printf("\nj = %d", j);
		
		switch (j){	
	
		    case OGS_FSM_ENTRY_SIG:
		        return OGS_FSM_NAME_ENTRY_SIG;
		 	case OGS_FSM_EXIT_SIG:
		 		return OGS_FSM_NAME_EXIT_SIG;
			case _SMF_EVT_S5C_MESSAGE:
		    	return "\"SMF_EVT_S5C_MESSAGE\"";
		    case _SMF_EVT_S6B_MESSAGE:
		    	return "\"SMF_EVT_S6B_MESSAGE\"";
		    case _SMF_EVT_GN_MESSAGE:
		        return "\"SMF_EVT_GN_MESSAGE\"";
		    case _SMF_EVT_GX_MESSAGE:
		        return "\"SMF_EVT_GX_MESSAGE\"";
		    case _SMF_EVT_GY_MESSAGE:
		        return "\"SMF_EVT_GY_MESSAGE\"";
		    case _SMF_EVT_N4_MESSAGE:
		        return "\"SMF_EVT_N4_MESSAGE\"";
		    case _SMF_EVT_N4_TIMER:
		        return "\"SMF_EVT_N4_TIMER\"";
		    case _SMF_EVT_N4_NO_HEARTBEAT:
		        return "\"SMF_EVT_N4_NO_HEARTBEAT\"";
		
		    case OGS_EVENT_SBI_SERVER:
		        return OGS_EVENT_NAME_SBI_SERVER;
		    case OGS_EVENT_SBI_CLIENT:
		        return OGS_EVENT_NAME_SBI_CLIENT;
		    case OGS_EVENT_SBI_TIMER:
		        return OGS_EVENT_NAME_SBI_TIMER;
		
		    case _SMF_EVT_NGAP_MESSAGE:
		        return "\"SMF_EVT_NGAP_MESSAGE\"";
		    case _SMF_EVT_NGAP_TIMER:
		        return "\"SMF_EVT_NGAP_TIMER\"";
		
		    case _SMF_EVT_5GSM_MESSAGE:
		        return "\"SMF_EVT_5GSM_MESSAGE\"";
		    case _SMF_EVT_5GSM_TIMER:
		        return "\"SMF_EVT_5GSM_TIMER\"";
		
		    default:
		      	break;
	
	    	ogs_error("Unknown Event[j]", j);
	    	return "UNKNOWN_EVENT";
	}
	}
	
	int main(){
	
	const char *tab[2][18];
	tab[0][0]=NULL;
	tab[1][0]="OGS_FSM_NAME_INIT_SIG";
	
	tab[0][1]="OGS_FSM_ENTRY_SIG";
	tab[1][1]="OGS_FSM_NAME_ENTRY_SIG";
	
	tab[0][2]="OGS_FSM_EXIT_SIG";
	tab[1][2]="OGS_FSM_NAME_EXIT_SIG";
	
	tab[0][3]="SMF_EVT_S5C_MESSAGE";
	tab[1][3]="\"SMF_EVT_S5C_MESSAGE\"";
	
	tab[0][4]="SMF_EVT_S6B_MESSAGE";
	tab[1][4]="\"SMF_EVT_S6B_MESSAGE\"";
	
	tab[0][5]="SMF_EVT_GN_MESSAGE";
	tab[1][5]="\"SMF_EVT_GN_MESSAGE\"";
	
	tab[0][6]="SMF_EVT_GX_MESSAGE";
	tab[1][6]="\"SMF_EVT_GX_MESSAGE\"";
	
	tab[0][7]="SMF_EVT_GY_MESSAGE";
	tab[1][7]="\"SMF_EVT_GY_MESSAGE\"";
	
	tab[0][8]="SMF_EVT_N4_MESSAGE";
	tab[1][8]="\"SMF_EVT_N4_MESSAGE\"";
	
	tab[0][9]="SMF_EVT_N4_TIMER";
	tab[1][9]="\"SMF_EVT_N4_TIMER\"";
	
	tab[0][10]="SMF_EVT_N4_NO_HEARTBEAT";
	tab[1][10]="\"SMF_EVT_N4_NO_HEARTBEAT\"";
	
	tab[0][11]="OGS_EVENT_SBI_SERVER";
	tab[1][11]="OGS_EVENT_NAME_SBI_SERVER";
	
	tab[0][12]="OGS_EVENT_SBI_CLIENT";
	tab[1][12]="OGS_EVENT_NAME_SBI_CLIENT";
	
	tab[0][13]="OGS_EVENT_SBI_TIMER";
	tab[1][13]="OGS_EVENT_NAME_SBI_TIMER";
	
	tab[0][14]="SMF_EVT_NGAP_MESSAGE";
	tab[1][14]="\"SMF_EVT_NGAP_MESSAGE\"";
	
	tab[0][15]="SMF_EVT_NGAP_TIMER";
	tab[1][15]="\"SMF_EVT_NGAP_TIMER\"";
	
	tab[0][16]="SMF_EVT_5GSM_MESSAGE";
	tab[1][16]="\"SMF_EVT_5GSM_MESSAGE\"";
	
	tab[0][17]="SMF_EVT_5GSM_TIMER";
	tab[1][17]="\"SMF_EVT_5GSM_TIMER\"";
	
	int Lok=0, Lwr=0, c=0, i, j=-1;
	
	for(i=0; i<18; i++){
	
		const char* tab_in = tab[0][i];
		const char* tab_control = tab[1][i];
		const char* tab_out = smf_event_get_name(tab_in, i-1);
		
		printf("\ntab_in      %s", tab_in);
		printf("\ntab_control %s", tab_control);
		printf("\ntab_out     %s", tab_out);
		
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
