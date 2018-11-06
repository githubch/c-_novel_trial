#include<iostream>
#include<string>
using namespace std;
struct MonCommand {
	string cmdString;
	string helpstring;
	string module;
	string req_perms;
	string availability;
};


#define COMMAND(parsesig, helptext, modulename, req_perms, avail) \
 {parsesig, helptext, modulename, req_perms, avail}


int main() {
	MonCommand cmd0 = {"a", "b", "c", "d", "e"};
	MonCommand cmd = COMMAND("tell " \
		"name=target,type=CephName " \
		"name=args,type=CephString,n=N", \
		"send a command to a specific daemon", "mon", "rw", "cli,rest");	
	cout <<"cmd.cmdString="<< cmd.cmdString << "\t" << "cmd.helpstring=" << cmd.helpstring << "\t" << "cmd.module=" << cmd.module << "\t" << "cmd.req_perms=" << cmd.req_perms << "\t" << cmd.availability << endl;
	return 0;
}
