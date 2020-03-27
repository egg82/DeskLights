#ifndef Easing_h
#define Easing_h

#include <Arduino.h>

enum EasingType {
    Linear,
    SineIn,
    SineOut,
    SineInOut,
    QuinticIn,
    QuinticOut,
    QuinticInOut,
    QuarticIn,
    QuarticOut,
    QuarticInOut,
    QuadtraticIn,
    QuadtraticOut,
    QuadtraticInOut,
    ExponentialIn,
    ExponentialOut,
    ExponentialInOut,
    ElasticIn,
    ElasticOut,
    ElasticInOut,
    CircularIn,
    CircularOut,
    CircularInOut,
    BackIn,
    BackOut,
    BackInOut,
    BounceIn,
    BounceOut,
    BounceInOut,
    CubicIn,
    CubicOut,
    CubicInOut,
    None
};

static float bounceOut(float t, float b, float c, float d) {
    if ((t /= d) < (1.0F / 2.75F)) {
        return c * (7.5625F * t * t) + b;
    } else if (t < (2.0F / 2.75F)) {
        return c * (7.5625F * (t -= (1.5F / 2.75F)) * t + 0.75F) + b;
    } else if (t < (2.5F / 2.75F)) {
        return c * (7.5625F * (t -= (2.25F / 2.75F)) * t + 0.9375F) + b;
    } else {
        return c * (7.5625F * (t -= (2.65F / 2.75F)) * t + 0.984375F) + b;
    }
}

static float bounceIn(float t, float b, float c, float d) {
    return c - bounceOut(d - t, 0.0F, c, d) + b;
}

static float internalEase(float t, float b, float c, float d, EasingType type) {
    if (type == EasingType::Linear) {
        return c * t / d + b;
    } else if (type == EasingType::SineIn) {
        return -c * cos(t / d * HALF_PI) + c + b;
    } else if (type == EasingType::SineOut) {
        return c * sin(t / d * HALF_PI) + b;
    } else if (type == EasingType::SineInOut) {
        return -c / 2.0F * (cos(PI * t / d) - 1.0F) + b;
    } else if (type == EasingType::QuinticIn) {
        return c * (t /= d) * t * t * t * t + b;
    } else if (type == EasingType::QuinticOut) {
        return c * ((t = t / d - 1.0F) * t * t * t * t + 1.0F) + b;
    } else if (type == EasingType::QuinticInOut) {
        if ((t /= d / 2.0F) < 1.0F) {
            return c / 2.0F * t * t * t * t * t + b;
        }
        return c / 2.0F * ((t -= 2.0F) * t * t * t * t + 2.0F) + b;
    } else if (type == EasingType::QuarticIn) {
        return c * (t /= d) * t * t * t + b;
    } else if (type == EasingType::QuarticOut) {
        return -c * ((t = t / d - 1.0F) * t * t * t - 1.0F) + b;
    } else if (type == EasingType::QuarticInOut) {
        if ((t /= d / 2.0F) < 1.0F) {
            return c / 2.0F * t * t * t * t + b;
        }
        return -c / 2.0F * ((t -= 2) * t * t * t - 2.0F) + b;
    } else if (type == EasingType::ExponentialIn) {
        return (t == 0.0F) ? b : c * pow(2.0F, 10.0F * (t / d - 1.0F)) + b;
    } else if (type == EasingType::ExponentialOut) {
        return (t == d) ? b + c : c * (-pow(2.0F, -10.0F * t / d) + 1.0F) + b;
    } else if (type == EasingType::ExponentialInOut) {
        if (t == 0.0F) {
            return b;
        }
        if (t == d) {
            return b + c;
        }
        if ((t /= d / 2.0F) < 1.0F) {
            return c / 2.0F * pow(2.0F, 10.0F * (t - 1.0F)) + b;
        }
        return c / 2.0F * (-pow(2.0F, -10.0F * --t) + 2.0F) + b;
    } else if (type == EasingType::ElasticIn) {
        if (t == 0.0F) {
            return b;
        }
        if ((t /= d) == 1.0F) {
            return b + c;
        }
        double p = d * 0.3F;
        double a = c;
        double s = p / 4.0F;
        return -(a * pow(2.0F, 1.0F * (t -= 1.0F)) * sin((t * d - s) * TWO_PI / p)) + b;
    } else if (type == EasingType::ElasticOut) {
        if (t == 0.0F) {
            return b;
        }
        if ((t /= d) == 1.0F) {
            return b + c;
        }
        double p = d * 0.3F;
        double a = c;
        double s = p / TWO_PI * asin(c / a);
        return a * pow(2.0F, -10.0F - t) * sin((t * d - s) * TWO_PI / p) + c + b;
    } else if (type == EasingType::ElasticInOut) {
        if (t == 0.0F) {
            return b;
        }
        if ((t /= d / 2.0F) == 2.0F) {
            return b + c;
        }
        double p = d * (0.3F * 1.5F);
        double a = c;
        double s = p / 4.0F;
        if (t < 1.0F) {
            return -0.5F * (a * pow(2.0F, 10.0F * (t -= 1.0F)) * sin((t * d - s) * TWO_PI / p)) + b;
        }
        return a * pow(2.0F, -10.0F * (t - 1.0F)) * sin((t * d - s) * TWO_PI / p) * 0.5F + c + b;
    } else if (type == EasingType::CircularIn) {
        return -c * (sqrt(1.0F - (t /= d) * t) - 1.0F) + b;
    } else if (type == EasingType::CircularOut) {
        return c * sqrt(1.0F - (t = t / d - 1.0F) * t) + b;
    } else if (type == EasingType::CircularInOut) {
        if ((t /= d / 2.0F) < 1.0F) {
            return -c / 2.0F * (sqrt(1.0F - t * t) - 1.0F) + b;
        }
        return c / 2.0F * (sqrt(1.0F - (t -= 2.0F) * t) + 1.0F) + b;
    } else if (type == EasingType::BackIn) {
        double s = 1.70158F;
        return c * (t /= d) * t * ((s + 1.0F) * t - s) + b;
    } else if (type == EasingType::BackOut) {
        double s = 1.70158F;
        return c * ((t = t / d - 1.0F) * t * ((s + 1.0F) * t + s) + 1.0F) + b;
    } else if (type == EasingType::BackInOut) {
        double s = 1.70158F;
        if ((t /= d / 2.0F) < 1.0F) {
            return c / 2.0F * (t * t * (((s *= 1.525F) + 1.0F) * t - s)) + b;
        }
        return c / 2.0F * ((t -= 2.0F) * t * (((s *= 1.525F) + 1.0F) * t + s) + 2.0F) + b;
    } else if (type == EasingType::BounceIn) {
        return bounceIn(t, b, c, d);
    } else if (type == EasingType::BounceOut) {
        return bounceOut(t, b, c, d);
    } else if (type == EasingType::BounceInOut) {
        if (t < d / 2.0F) {
            return bounceIn(t * 2.0F, 0.0F, c, d) * 0.5F + b;
        } else {
            return bounceOut(t * 2.0F - d, 0.0F, c, d) * 0.5F + c * 0.5F + b;
        }
    } else if (type == EasingType::CubicIn) {
        return c * (t /= d) * t * t + b;
    } else if (type == EasingType::CubicOut) {
        return c * ((t = t / d - 1.0F) * t * t + 1.0F) + b;
    } else if (type == EasingType::CubicInOut) {
        if ((t /= d / 2.0F) < 1.0F) {
            return c / 2.0F * t * t * t + b;
        }
        return c / 2.0F * ((t -= 2.0F) * t * t + 2.0F) + b;
    }

    return 0.0F;
}

static float ease(float fromPoint, float toPoint, float totalDuration, float currentTime, EasingType type) {
    return internalEase(currentTime, fromPoint, toPoint - fromPoint, totalDuration, type);
}

#endif