#define MAIN_FILE
#include "../includes/scop.h"

int		main(int ac, char **av)
{
	read_obj(ac, av);//incomplete
	print_list(lst);//debug
	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("Lighthouse3D- GLUT Tutorial");
	glutDisplayFunc(render_scene);
	glutReshapeFunc(change_size);
	glutIdleFunc(render_scene);
	glutKeyboardFunc(process_normal_keys);
	glutSpecialFunc(process_special_keys);
	glutMainLoop();
	return (1);
}
