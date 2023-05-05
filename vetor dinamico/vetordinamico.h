//** definições das estruturas de dado **//
struct vdinamico{
    void *dados;
};
typedef struct vdinamico TVDinamico;

TVDinamico *criarVD();

void inserirVD(TVDinamico *vd, int carga, int pos);
int removerVD(TVDinamico *vd, int pos );
int acessarVD(TVDinamico *vd, int pos);
void ordenarVD(TVDinamico *vd);