#include <windows.h>
#include <gl/gl.h>
#include <GL/glu.h>
#include "include/lista.h"
#include "include/util.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

static float fov = 45.0f;

void SetupProjection(int largura, int altura) {
    if(altura == 0)
        altura = 1;

    glViewport(0, 0, largura, altura);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(fov, (GLfloat)largura / (GLfloat)altura, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "Lista",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          1024,
                          1024,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor(.6f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            double m[8][3] = {
                {MIN, MAX, MIN_DEP},
                {MIN, MIN, MIN_DEP},
                {MAX*1.5, MIN, MIN_DEP},
                {MAX*1.5, MAX, MIN_DEP},

                {MAX*1.5, MIN, MAX_DEP},
                {MIN, MIN, MAX_DEP},
                {MIN, MAX, MAX_DEP},
                {MAX*1.5, MAX, MAX_DEP}
            };

            glPushMatrix();
            glRotatef(theta, 1.0f, 1.0f, 0.0f);

            glTranslated(-1.5, 0, 0);
            form_indices(m, 0.998);

            glTranslated(0.5, 0, 0);
            form_indices(m, 0.998);

            glTranslated(0.5, 0, 0);
            form_indices(m, 0.998);

            glTranslated(0.5, 0, 0);
            form_indices(m, 0.998);

            glTranslated(0.5, 0, 0);
            form_indices(m, 0.998);

            glTranslated(0.5, 0, 0);
            form_indices(m, 0.998);

            glPopMatrix();

            SwapBuffers(hDC);

            theta += .0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_SIZE:
            SetupProjection(LOWORD(lParam), HIWORD(lParam));
            return 0;

        case WM_MOUSEWHEEL: {
            short delta = GET_WHEEL_DELTA_WPARAM(wParam);
            if(delta > 0 && fov > 5.0f)
                fov -= 2.0f;  // Zoom in

            if(delta < 0 && fov < 120.0f)
                fov += 2.0f; // Zoom out

            RECT rect;
            GetClientRect(hWnd, &rect);
            SetupProjection(rect.right, rect.bottom);
            return 0;
        }

        case WM_KEYDOWN:
            if (wParam == VK_UP && fov > 5.0f)
                fov -= 2.0f;   // Zoom in
            if (wParam == VK_DOWN && fov < 120.0f)
                fov += 2.0f; // Zoom out
            RECT rect;
            GetClientRect(hWnd, &rect);
            SetupProjection(rect.right, rect.bottom);
            return 0;

        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
        }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

/*
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                break;
            }
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}
*/

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

