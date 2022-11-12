//zayyneb messaoudi  3IM1

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

static int slices = 50;
static int stacks = 50;

/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glDisable( GL_LIGHTING );

    //neck
    glPushMatrix();
        glColor4f(1.0f, 0.7f, 0.0f, 0.0f);
        glTranslated(-0.4,1.35,-6);
        glRotated(60,1,0,0);
        glScaled(1,1,1.5);
        glutSolidCube(0.2f);
    glPopMatrix();

    //head
    glPushMatrix();
        glColor4f(1.0f, 0.7f, 0.0f, 0.0f);
        glTranslated(-0.4,2,-6);
        glRotated(a,1,1,1);
        glutSolidSphere(0.6,slices,stacks);
    glPopMatrix();

    //right eye
    glPushMatrix();
        glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
        glTranslated(-0.15,2,-5.5);
        glRotated(a,1,1,1);
        glutSolidSphere(0.12,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glColor4f(0,0,0,0);
        glTranslated(-0.15,2,-5.5);
        glRotated(a,1,1,1);
        glutSolidSphere(0.07,slices,stacks);
    glPopMatrix();

    //left eye
    glPushMatrix();
        glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
        glTranslated(-0.6,2,-5.5);
        glRotated(a,1,1,1);
        glutSolidSphere(0.12,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glColor4f(0,0,0,0);
        glTranslated(-0.6,2,-5.5);
        glRotated(a,1,1,1);
        glutSolidSphere(0.07,slices,stacks);
    glPopMatrix();

    //nose
    glPushMatrix();
        glColor4f(0.9f, 0.7f, 0.0f, 0.0f);
        glTranslated(-0.35,1.7,-5.5);
        glScaled(1,1,1.5);
        glutSolidCone(0.07,0.3,slices,stacks);
    glPopMatrix();

    //left arm
    glPushMatrix();
        glColor4f(1.0f, 0.7f, 0.0f, 0.0f);
        glTranslated(-2.35,-0.2,-6);
        glRotated(90,2,0.5,0);
        glScaled(1,2,1);
        glutSolidCube(0.3);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.3f, 0.0f, 0.9f);
        glTranslated(-1.55,0.59,-6);
        glRotated(45,2,-1,0);
        glScaled(0.2,0.2,1.8);
        glutSolidCube(1.3);
    glPopMatrix();

    //right arm
    glPushMatrix();
        glColor4f(1.0f, 0.7f, 0.0f, 0.0f);
        glTranslated(1.35,-0.28,-6);
        glRotated(90,2,-1,0);
        glScaled(1,2,1);
        glutSolidCube(0.3);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.3f, 0.0f, 0.9f);
        glTranslated(0.65,0.59,-6);
        glRotated(45,2,1,0);
        glScaled(0.2,0.2,1.8);
        glutSolidCube(1.3);
    glPopMatrix();

    //left leg
    glPushMatrix();
        glColor4f(0.0f, 0.0f, 0.8f, 0.0f);
        glTranslated(-0.9,-2,-6);
        glRotated(60,1,0,0);
        glScaled(0.2,0.2,1.8);
        glutSolidCube(1.7f);
    glPopMatrix();

    //right leg
    glPushMatrix();
        glColor4f(0.0f, 0.0f, 0.8f, 0.0f);
        glTranslated(0,-2,-6);
        glRotated(60,1,0,0);
        glScaled(0.2,0.2,1.8);
        glutSolidCube(1.7f);
    glPopMatrix();

    //body
    glPushMatrix();
        glColor3f(0.3f, 0.0f, 1.0f);
        glTranslated(-0.4,0.1,-6);
        glRotated(60,1,0,0);
        glScaled(1.5,1.3,2);
        glutSolidCube(1);
    glPopMatrix();

    glDisable(GL_DEPTH_TEST);

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1280,790);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Human body");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
