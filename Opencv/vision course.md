## Vision Course

- #### camera：

  - Pinhole（3D-->2D）
    - an idea mode
    - length and angle can't be trusted

  * Pinhole

    * to big :many stream of light come in 
    * to small:  we can't neglect interference of light

    * problem with lenses:

      * other project to a "circle of confusion"
        $$
        1/d+1/d=1/f
        $$

  * depth of field

    * changing the aperture size affects depth of field

    * field of view   (FOV)

      * $$
        arctan(d/2f)
        $$

      * FOV越大，越容易产生近大远小的情况

  * Lens Flaws : Chromatic Aberration
    * color fringes near edges of images

  * Radial Distortion:
    * barrel
    * pincushion
    * orthoscopic

* #### color:

  * cameras capture:
    * a color is represented as a [R,G,B] three vector
    * At each point, there are three sensors to capture the stimules of red, green, blue lights.

  * 光源-> 反射-> capture

  * Specify color Numerically
    * Color Matching Function
    * XYZ Color Space
      * Linear transformation from XYZ to sRGB
    * RGB Color Space
      * G  : 人眼更敏感
    * YUV  Color Space   (can transform from RGB)

