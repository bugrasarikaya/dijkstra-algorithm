#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define INFINITY 9999
char edsger_dijkstra[67][105] = { //ASCII picture of Edsger Dijkstra.
	{"                     . . ..................................:...:::ir7i.::i:  ..........................:"},
	{"                      ... ... ............................:...::r::.::iiri7v:..........................:"},
	{"                         .     ........................  ...:vY7ii .  .L:7vv7:::..::...................:"},
	{"                          . . . . ..................... ..:i:::i::i.:::rJLri7ir7:.i:...................."},
	{"                       . ... . . ..... ...............:7Jvii.   .L:.:JR.:.. ...... ..  ................:"},
	{"                      . . ... . ..... .........   ..iYXgE7:.. ...ir ruJ: .: .     .     ....... .......:"},
	{"                   .   ......... .............    ..ii        .i..i. :i: .: ..     . ..  ..............:"},
	{"              .   . . ..................... . ... .   .     .   . ..: ::  i. .. ..... ...  ............."},
	{"             . .     . ............................. .:... i.  ..... :.: ...  .  . . .   .   ..........:"},
	{".       . . . ... . ....................................iY7...  . .:  ... . ... . ..  .   .............:"},
	{" .       ... ..........................:.. ......:i:..:r::......   .   ... ......... ... ..... ..:.....:"},
	{".   . . ................................. ......:.:r:...... ....      . ................... ... .......:"},
	{" . . . .................................   :ii::.:.:ii:.. .    ..... ...................:..:...........:"},
	{"... . ... .............................. .u7r::.... .           .   .  .. .................:...........:"},
	{"....................................... :MZYJJvJ7iir:... .::. .. . . ..... . ... ......: .  ...........:"},
	{"..............................:.:.:... :BBQBBBBBQdQgMggPKPqISUUuu77r777rr::.:...  . ..... . ..........::"},
	{".............................:.:.:.:...QBBBBQBQBBBBBBBQBBBBBBBBBgbXSSK5SsLvL7r::.. :::..   . ..........:"},
	{"..............................:.:.:...PBBBBBBBBQBBBBBQBQBBBBBBBBBMDbqXqSS12JL77i:... ..     .   . .....:"},
	{"...............................:.:.. 7BBBBBBBBBBBBQBBBBBBBQBQBBQRQRZXXI52K5J7r77r:..             . ....:"},
	{"........................:.:.:.:.:::..KBBBBBBBBBBBBBBBBBBBQBBBBBRQQMK5j1J21uvrr7sY.... .           ......"},
	{"...........:.........:.:::.:.:::::...QBBBBBBBBBBBBBBQBBBBBBBBBQQgPujj1JuUIsLrvL2r...             ......:"},
	{"........:.:.:::.:::::::.::::::::::: iBBBBBBBBBBBBBBBBBBBBBBBBQRgRqsvUIqKS1j7vYY7i..                 ...."},
	{".:.:.:.::::::i:i:iiiiiirirrririiii:.YBBBBBBBBBQBBBBBBBBBBBQBQQZZZb1KZZXKjv77YYr7:..                . . ."},
	{"::::::iiiirr7r7r7r7777v7v77777v7v77:EQBBBBBBBBBBBBBBBBBQBQQQQggP525KDdd2s77vvrvi... .               . .."},
	{":iiiirr7777v7v7LvsLJYJs1jusU155PddSsQBQBBBBBBBBBBBBBBBBBBBQQgRgEXqISKq2s77v7rri:  ..             .   . ."},
	{"r777v7LvYvJJUuI2IISSKKPqbPEgBBBPUr.YBBBBBBBBBBBBBQBBBBBQBQQQQDbIISXU51j7rr7iii:.. ..            ... ...."},
	{"7JvYLuJUu55qKbdDZgDggQgRRBQBJ:.    2BQgIYrr5EBBBRBBBQBBBQBBBQgbPKqXKKSu7rr::::..               ........:"},
	{"s2UU5IXKPPEZgMQQBBBBBBBBBBBB    ...   ....   iJJKQBQPXgMgZRDQQQBBdPqPS1r:::......             .........."},
	{"5DXdbZZMMQQBBBQBBBBBBBBBBBBB.  ....:.  ..:::. .jBBMLii.i:iirvXEDdPdP557:.:.:.:::.. .          .........:"},
	{"ZQMQBBBBBBBBBBBBBBBBBBBBBBBBBr .:::::  .   ... iBBPi:..   . .:7vIudgIvr::.:::::::...... .    .:.:.:....:"},
	{"QBBBBBBBBBBBBBQBBBBBBBQBBBQBBB  .:sP7r2S. .i.       .....:::::..   ....:.:...:::...... ..   .:.:::.:.:.:"},
	{"BQBBBBBQBBBBBBBBBBBBBBBBBBBQBB7 ..RBBBBBQQMDBK ..   . ..:  .      .     ............... ..rPDr:.:::.:.::"},
	{"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB . 7BBBQBBBBBB1.BBBJ  ...::.7   ..  ..... ...   ..........iri..::::.:.:.:"},
	{"BBBBBBBBBBBBBQBQBBBBBBBBBBBBBBBI.i:bBBBBBQBBB QQBbr ....vPKqqvrYL.. :.  ....:::::.............:::::....:"},
	{"QBBBQBBBBBBBBBBBBBBBBBBBQBBBBBBBMI:.7IdBBBQB iBBgr..  .bgBgBBBPXIUui:  riiiiiri:.......:::...:::::.:...:"},
	{"BBBQBQBBBBBBBBBBBBBBBBBBBBBBBBBQBQBj:.  :.. 7BBBXi:i.  QBRDPZggbKj7Lr 717i:::.::.....:..::: :::::.:....:"},
	{"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBQBBQBBQEDgBBBBBqv::r: :qRMd2U1s77sP :Ur::.:.:......::......::::........"},
	{"BBBQBBBBBQBBBBBBBBBBBBBBBBBBBBBBM2BQBBBQBBBBBBBMP7: .7L:..::rrvu5qZi.Y7:............::. ....i::.:.:....."},
	{"QBQBBBBBBBBBBBBBBBBBBBBBBBQBBBQBgsBBBBBBERBBBBRUr:.:7riDBBXv:.....  :................. ....iii::::.....:"},
	{"BBBBBQBBBBBBBBBBBBBQBBBBBBBBBQBBd1BQBBBdBQBMM1i .:iJ27..PBBBBBM17::.......................7ri::.:......."},
	{"BBBBQBBBBBQBBBBBBBBBBBQBBBQBBBBB5jBBBBDgMgUv:.     ...  :URBQBQBgXLr::...............::.:v77i:::........"},
	{"BBBQBBBBBBBBBBBBBBBQBBBBBBBBBBBBU7BBQSKUvirKK....:.   .:Yv1gQPX2jr7i:.:...... ... . . .:uY7rri:........."},
	{"BBBBQBBBQBQBBBBBQBQBBBBBBBBBBBQBv:Dqrr77riiqj:PqvS1.:7vvUP1IbZIY7i:....:........   ..rjXuv77ri::........"},
	{"BBBQBBBQBQBBBBBBBQBBBBBBBQBBBQBBK.1i:r:i7iii:ruYrr7iiJuiisILI2qUvr:.::.........  .BBBQZ5ULvr7ii::......."},
	{"QBBBQBQBQBBBQBBBBBQBBBQBBBQBBBBBEiv:..  .:i:..r.:i:..i:irir::v2E1Yi..:.. .....   YBBQgqX2uvvrri:...... ."},
	{"BBBBBQBQBQBQBQBBBBBQBBBQBBBBBBBBP:ivL:rqdJLrYi:   . .:. :.:::.r1K7:...::....... .RBBBRgPK1jvv7r::.... .."},
	{"QBQBQBQBQBQBQBQBQBBBQBBBQBBBQBBBI.7I7UBBBBBBQBQR2i..      ..:. :vv:...........  :BBBBQMZXSus77ri:......."},
	{"BQQQBQBQBQBQBQQQBQBQBBBBBQBBBBBQb:7::UQBBQQbPuPgBMEUsr::..:..  .:.............. bQBBBBQgEX5jY7r::......."},
	{"RBQBQBQQQBQBQBQBQBQBQBBBBBQBQBBBPir::i7gb2jJv7iruPqU5PI2s1Ju:. . ............:..EBQBBBQQEb51vvri:......."},
	{"QBQQQQBQQQBQBQBQBQBQBQBQBBBBBBBQ:i7:::jSjLsvLrr:iv2rrL1vvJLv:::..................gBBBQBMgKXuY77i:......."},
	{"QBRQQQQQQBQQQBQQQBQBQBQBQBQBQBBX .i::usi77rrir.::juii:irr7i..::...............:. iBBBBQQEPS2Y7ri::......"},
	{"QBQRQQQQQRQRQQQQQQQQBQBQBQBBBBBBi :iirii7vviri.iiv7.77.:7::...................:...gQBBBMZPq1L77i:......."},
	{"gBRQQQRQRQQQRQQBQQQBQBQBBBQBBBBBBi.:..:2JIi:v7vr:s7.:s:::...:...:..........:.:::...2BBBBZdXIYvri::......"},
	{"QBQRQRQMQRQQQRQQQQQQBQBQBQBQBQBBBB: :.i1ii::v:7v:vi..::.:.........:.....:...::..::. iqBBQZPUY7ri:......."},
	{"gBRQRQMQRQRQQQRQQQQBQQRQQQgQQBQBBBP....Yi::....:.:............ ............:...:::. ...vIdPIL7ri:......."},
	{"RBQRQMQMQMQMQMQMRgQRQgMgQgQQBBBBBBQXP.  . ... . ......... ....... ..............:...:.  .:7Ls7r::......."},
	{"MBgRMQMQMQRQMRMQDMRQgggRRQMQBBBBBBUUBZr    .......  ...  ... . . ..............:.. .::...  .:i::........"},
	{"RBMMQMRMQMQRMgQRgZgggDggMMQQBQBQBQrrBBBg7 .:. .. .. ... . . . ... .......  ....... .:...... ....... . .."},
	{"MBMRRRMMgggMDMggdEbEbDgQMQQBBBQgBB:iBBBBBJ.7I7:....... ....... . . ..... ........  ..:.............. . ."},
	{"MBMgRgMDgDgEEbEqPXU2PPDQQRQQBBg2BB: QBBgDgL :ss:.   . . ..... . ....... ........  ..:.        . . ......"},
	{"DBggDgEgZZPPqPPPIj1PPZZQQQQQBBdsBBi JBggdRDj..v1r... .   . . ......... ... ....   ....               ..."},
	{"gBDdZdZdEbP555P52YuKZZgdMQQQBBSsBBY :bP5ZQgPJi:rJvvr:..   . . . ....... . .....  .. ..                .."},
	{"ZBEDEEPbqPXSUSX2L772PDZZDRMQBQsUQBP  I5IPEQdE2Yri77vr:....   . ....... .......  ... ..                 ."},
	{"ZQZdEPqqPSK5XI1v7ir1dDMgMDQQBQ2KBQQ  7IjjXPRDPSrYrLri:::........... .........   .....               ...:"},
	{"PQPbKXSqSI22I5YY77sbEMDMgRRQQQj1BBBi iS2vL2Pugj2i::.:::r:::....... .........    .. .              .....:"},
	{"EBMgZbEPPKPPEKP55JuPQQBBBBBBBBPIBBBs 7QMEq5YJ1uIL1i:... . . ............... . ...  .              .   .."} };
char intro_text[6][99] = {	{ "       ____  _  _ _        _             _          _    _                  _ _   _               " },
							{ "      |  _ \\(_)(_) | _____| |_ _ __ __ _( )___     / \\  | | __ _  ___  _ __(_) |_| |__  _ __ ___  " },
							{ "      | | | | || | |/ / __| __| '__/ _` |// __|   / _ \\ | |/ _` |/ _ \\| '__| | __| '_ \\| '_ ` _ \\ " },
							{ "      | |_| | || |   <\\__ \\ |_| | | (_| | \\__ \\  / ___ \\| | (_| | (_) | |  | | |_| | | | | | | | |" },
							{ "      |____/|_|/ |_|\\_\\___/\\__|_|  \\__,_| |___/ /_/   \\_\\_|\\__, |\\___/|_|  |_|\\__|_| |_|_| |_| |_|" },
							{ "             |__/                                          |___/                                  " }};
int graph_existing[8][8] = //This graph is taken from our presentation and this link: https://youtu.be/jT3c45XkPTg (Last visited Dec. 4, 2020.)
	{ { 0, 20, INFINITY, 80, INFINITY, INFINITY, 90, INFINITY },
	{ INFINITY, 0, INFINITY, INFINITY, INFINITY, 10, INFINITY, INFINITY},
	{ INFINITY, INFINITY, 0, 10, INFINITY, 50, INFINITY, 20},
	{ INFINITY, INFINITY, 10, 0, INFINITY, INFINITY, 20, INFINITY },
	{ INFINITY, 50, INFINITY, INFINITY, 0, INFINITY, 30, INFINITY },
	{ INFINITY, INFINITY, 10, 40, INFINITY, 0, INFINITY, INFINITY },
	{ 20, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, 0, INFINITY },
	{ INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, 0} };
void display_graph(int *graph, int vertices_number) {
	for (int i = 0; i < vertices_number; i++) {
		for (int j = 0; j < vertices_number; j++) {
			printf("%d ", *(graph + i * vertices_number + j));
		}
		printf("\n");
	}
}
int find_min_weighted_vertex(int weight[], int *not_selected, int vertices_number) { //Finds minimum weighted vertex.
	int min;
	for (int i = 0; i < vertices_number; i++) {
		if (not_selected[i]) { //Previous function results are selected nodes.
			min = weight[i];
			break;
		}
	}
	for (int i = 0; i < vertices_number; i++) {
		if (weight[i] < min && not_selected[i]) min = weight[i];
	}
	for (int i = 0; i < vertices_number; i++) {
		if (weight[i] == min && not_selected[i]) {
			not_selected[i] = 0;
			return i;
		}
	}
	printf("FAILURE\n");
	exit(1);
}
void min_distance(int min_weighted_node, int *graph, int *weight, int path[], int vertices_number) { //Implements the edge relaxation.
	for (int i = 0; i < vertices_number; i++) {
		if (weight[min_weighted_node] + *(graph + min_weighted_node * vertices_number + i) < weight[i]) {
			weight[i] = weight[min_weighted_node] + *(graph + min_weighted_node * vertices_number + i);
			path[i] = min_weighted_node; //Tracks path.
		}
	}
}
void display_result(int weight[], int path[], int vertices_number, int source_vertex) { //Displays shortest distances and paths.
	printf("Vertex\tDistance from source\tPath\n");
	for (int i = 0; i < vertices_number; i++) {
		printf("%d\t", i);
		if(weight[i]!= INFINITY)printf("%d\t\t\t", weight[i]);
		else printf("INFINITY\t\t");
		if (weight[i]!= INFINITY) {
			int destination = i;
			if (i != source_vertex) {
				int j = i;
				int *temp = (int *)malloc(vertices_number * sizeof(int));
				int k = 0;
				do {
					j = path[j];
					temp[k++] = j; //Inserts the path into temp array, reversely.
				} while (j != source_vertex);
				for (int i = k - 1; i >= 0; i--) {
					printf("%d-", temp[i]);
				}
			}
			printf("%d", destination);
		}
		else {
			printf("No path.");
		}
		printf("\n");
	}
	printf("\n");
}
void dijkstra(int *graph, int vertices_number, int source_vertex) { //Finds shortest distances from source and paths by using the Dijkstra's Algorithm.
	int *weight = (int *)malloc(vertices_number * sizeof(int));
	int *not_selected = (int *)malloc(vertices_number * sizeof(int));
	int *path = (int *)malloc(vertices_number * sizeof(int));
	for (int i = 0; i < vertices_number; i++) {
		path[i] = source_vertex;
	}
	int min_weighted_vertex;
	for (int i = 0; i < vertices_number; i++) { //Beginning of the Dijkstra's Algorithm.
		if (i == source_vertex) weight[i] = 0;
		else weight[i] = INFINITY;
		not_selected[i] = 1;
	}
	for (int i = 0; i < vertices_number; i++) { //Main of dijkstra function.
		min_weighted_vertex = find_min_weighted_vertex(weight, not_selected, vertices_number);
		min_distance(min_weighted_vertex, graph, weight, path, vertices_number);
	}
	display_result(weight, path, vertices_number, source_vertex);
}
int main() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 6;
	cfi.dwFontSize.Y = 10;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, 9, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi); //Adjusts font settings.
	HWND consoleWindow = GetConsoleWindow();
	int screen_x = GetSystemMetrics(SM_CXSCREEN);
	int screen_y = GetSystemMetrics(SM_CYSCREEN);
	int console_x = 663;
	int console_y = 800;
	SetWindowPos(consoleWindow, HWND_TOP, (screen_x - console_x) / 2, (screen_y - console_y) / 2 - 15, 663, 800, SWP_SHOWWINDOW); //Adjusts window settings.
	for (int i = 0; i < 67; i++) {
		printf("%s\n", edsger_dijkstra[i]);
	}
	for (int i = 0; i < 6; i++) {
		printf("%s\n", intro_text[i]);
	}
	Sleep(3000);
	system("cls");
	cfi.dwFontSize.X = 11;
	cfi.dwFontSize.Y = 23;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	SetWindowPos(consoleWindow, HWND_TOP, (screen_x - console_x) / 2, (screen_y - console_y) / 2 - 15, 663, 800, SWP_SHOWWINDOW);
	do {
		printf("1. Work on the existing graph.\n");
		printf("2. Enter a new graph.\n");
		printf("3. Clear screen.\n");
		printf("4. Exit.\n");
		printf("Select an option: ");
		int option;
		scanf_s("%d", &option);
		switch (option) {
		case 1:
			printf("\n");
			dijkstra((int*)graph_existing, 8, 0);
			break;
		case 2:
			printf("\nEnter the number of vertices: ");
			int vertices_number;
			while (scanf_s("%d", &vertices_number) != 1) getchar(); //If user enters characters instead of integers, this getchar() discards characters.
			int *graph_new = (int *)malloc(vertices_number * vertices_number * sizeof(int));
			printf("Enter the vertices (For infinite value, enter 9999):\n");
			for (int i = 0; i < vertices_number; i++)
				for (int j = 0; j < vertices_number; j++)
			while (scanf_s("%d", (graph_new + i * vertices_number + j)) != 1) getchar();
			printf("Enter the source vertex: ");
			int source_vertex;
			while (scanf_s("%d", &source_vertex) != 1) getchar();
			printf("\n");
			dijkstra((int*)graph_new, vertices_number, source_vertex);
			break;
		case 3:
			system("cls");
			break;
		default:
			return 0;
		}
	} while (1);
	
}