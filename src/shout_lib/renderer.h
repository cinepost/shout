#ifndef __Renderer_h__
#define __Renderer_h__

#include <string>
#include <vector>

#include "display.h"


class Renderer {
	public:
		Renderer();
                virtual ~Renderer();

                int     render(int frame);
                float   getFPS(); // return scene or this fps value with scene being superior

        public:
                virtual int render(float time) = 0;
		
	private:
                float   fps = 25.0; // default fps
                Display *display = 0;
};


#endif // __Renderer_h__