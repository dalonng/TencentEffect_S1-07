//
//  XmagicConstant.h
//
//  Created by tao yue on 2023/4/24.
//

#ifndef XmagicConstant_h
#define XmagicConstant_h

#pragma mark - 已废弃，请使用新接口setEffect对应的参数。下面是 美颜/美体/滤镜/动效/分割/美妆 使用中的参数propertyType
#pragma mark - Deprecated, please use the corresponding parameter in the new setEffect API.The following is the parameter propertyType used in beauty/body/lut/motion/segmentation/makeup deprecated
/**
 美颜        beauty
 */
static NSString * const Category_BEAUTY __attribute__((deprecated)) = @"beauty";
/**
 美体        body
 */
static NSString * const Category_BODY_BEAUTY __attribute__((deprecated)) = @"body";
/**
 滤镜        lut
 */
static NSString * const Category_LUT __attribute__((deprecated)) = @"lut";
/**
 动效/分割/美妆
 motion/segmentation/makeup
 */
static NSString * const Category_MOTION __attribute__((deprecated)) = @"motion";
/**
 美妆      makeup
 */
static NSString * const Category_MAKEUP __attribute__((deprecated)) = @"custom";

#pragma mark - setEffect接口中的参数effectName
#pragma mark - Parameter 'effectName' in the setEffect API.
/**
 滤镜      lut
 */
static NSString * const EFFECT_LUT = @"lut";
/**
 美妆      makeup
 */
static NSString * const EFFECT_MAKEUP = @"makeup";
/**
 轻美妆      light makeup
 */
static NSString * const EFFECT_LIGHT_MAKEUP = @"light.makeup";
/**
 动效      motion
 */
static NSString * const EFFECT_MOTION = @"motion";
/**
 分割/绿屏分割/自定义背景      segmentation/green screen segmentation/custom segmentation
 */
static NSString * const EFFECT_SEGMENTATION = @"segmentation";


#pragma mark - 下面是 美颜/美体/滤镜/动效/分割/美妆 使用中的参数propertyName(旧接口)/effectName(新接口)
#pragma mark - The following is the parameter propertyName(old)/effectName(new) used in beauty/body/lut/motion/segmentation/makeup
/**
 使用XMagic中的configPropertyWithType接口时，不同的美颜场景，传入不同的propertyName。
 iOS sdk在version2.6版本已经兼容了安卓在BeautyConstant.java中定义的常量
 When using the configPropertyWithType interface in XMagic, different propertyNames are passed in for different beautification scenarios.
  The iOS sdk is compatible with the constants defined by Android in BeautyConstant.java in version 2.6
 */
#pragma mark - 美颜      beauty

/**
 美白      whiten
 */
static NSString * const BEAUTY_WHITEN = @"beauty.lutFoundationAlpha";
/**
 美白2   whiten2
 */
static NSString * const BEAUTY_WHITEN2 = @"beauty.lutFoundationAlpha2";
/**
 美白3   whiten3
 */
static NSString * const BEAUTY_WHITEN3 = @"beauty.lutFoundationAlpha3";
/**
 美黑1 black1
 */
static NSString * const BEAUTY_BLACK1 = @"beauty.lutBlackAlpha1";
/**
 美黑2 black2
 */
static NSString * const BEAUTY_BLACK2 = @"beauty.lutBlackAlpha2";
/**
 磨皮      smooth
 */
static NSString * const BEAUTY_SMOOTH = @"smooth.smooth";
/**
 红润      ruddy
 */
static NSString * const BEAUTY_ROSY = @"smooth.rosy";
/**
 对比度      contrast
 */
static NSString * const BEAUTY_CONTRAST = @"beauty.imageContrastAlpha";
/**
 饱和度      saturation
 */
static NSString * const BEAUTY_SATURATION = @"smooth.saturation";
/**
 清晰度      sharpen
 */
static NSString * const BEAUTY_CLEAR = @"beauty.lutClearAlpha";
/**
 锐化  Sharpen
 */
static NSString * const BEAUTY_SHAPE = @"smooth.sharpen";
/**
 大眼      enlarge eye
 */
static NSString * const BEAUTY_ENLARGE_EYE = @"basicV7.enlargeEye";
/**
 瘦脸-自然      thin face - nature
 */
static NSString * const BEAUTY_FACE_NATURE = @"basicV7.natureFace";
/**
 瘦脸-女神      thin face - godness
 */
static NSString * const BEAUTY_FACE_GODNESS = @"basicV7.godnessFace";
/**
 瘦脸-英俊      thin face - god
 */
static NSString * const BEAUTY_FACE_MALE_GOD = @"basicV7.maleGodFace";
/**
 v脸        v face
 */
static NSString * const BEAUTY_FACE_V = @"basicV7.vFace";
/**
 收下颌       face Jaw
 */
static NSString * const BEAUTY_FACE_JAW = @"basicV7.faceJaw";
/**
 窄脸      narrow face
 */
static NSString * const BEAUTY_FACE_THIN = @"basicV7.thinFace";
/**
 短脸      short face
 */
static NSString * const BEAUTY_FACE_SHORT = @"basicV7.shortFace";
/**
 脸型      basic face
 */
static NSString * const BEAUTY_FACE_BASIC = @"liquefaction.basic3";
/**
 染发      hair color
 */
static NSString * const BEAUTY_HAIR_COLOR_LUT = @"beauty.hairColorLut";
/**
 口红      lips
 */
static NSString * const BEAUTY_MOUTH_LIPSTICK = @"beauty.faceFeatureLipsLut";
/**
 腮红      redcheeks
 */
static NSString * const BEAUTY_FACE_RED_CHEEK = @"beauty.faceFeatureRedCheek";
/**
 立体      softlight
 */
static NSString * const BEAUTY_FACE_SOFTLIGHT = @"beauty.faceFeatureSoftlight";
/**
 眼影 eye shadow
 */
static NSString * const BEAUTY_FACE_EYE_SHADOW = @"beauty.faceFeatureEyesMakeup.eyeShadow";
/**
 眼线 eye liner
 */
static NSString * const BEAUTY_FACE_EYE_LINER = @"beauty.faceFeatureEyesMakeup.eyeLiner";
/**
 睫毛 eyelash
 */
static NSString * const BEAUTY_FACE_EYELASH = @"beauty.faceFeatureEyesMakeup.eyelash";
/**
 眼影亮片 eye sequins
 */
static NSString * const BEAUTY_FACE_EYE_SEQUINS = @"beauty.faceFeatureEyesMakeup.eyeSequins";
/**
 眉毛 eyebrow
 */
static NSString * const BEAUTY_FACE_EYEBROW = @"beauty.faceFeatureEyesMakeup.eyebrow";
/**
 美瞳 eyeball
 */
static NSString * const BEAUTY_FACE_EYEBALL = @"beauty.faceFeatureEyesMakeup.eyeball";
/**
 双眼皮 eyelids
 */
static NSString * const BEAUTY_FACE_EYELIDS = @"beauty.faceFeatureEyesMakeup.eyelids";
/**
 卧蚕 eyewocan
 */
static NSString * const BEAUTY_FACE_EYEWOCAN = @"beauty.faceFeatureEyesMakeup.eyewocan";
/**
 瘦颧骨      thin cheek
 */
static NSString * const BEAUTY_FACE_THIN_CHEEKBONE = @"basicV7.cheekboneThin";
/**
 下巴      chin
 */
static NSString * const BEAUTY_FACE_THIN_CHIN = @"basicV7.chin";
/**
 额头      forehead
 */
static NSString * const BEAUTY_FACE_FOREHEAD = @"basicV7.forehead";
/**
 亮眼      eye lighten
 */
static NSString * const BEAUTY_EYE_LIGHTEN = @"beauty.eyeLighten";
/**
 眼距      eye distance
 */
static NSString * const BEAUTY_EYE_DISTANCE = @"basicV7.eyeDistance";
/**
 眼角      eye angle
 */
static NSString * const BEAUTY_EYE_ANGLE = @"basicV7.eyeAngle";
/**
 眼宽     eye width
 */
static NSString * const BEAUTY_EYE_WIDTH = @"basicV7.eyeWidth";
/**
 眼高     eye height
 */
static NSString * const BEAUTY_EYE_HEIGHT = @"basicV7.eyeHeight";
/**
 眼睛位置     eye height
 */
static NSString * const BEAUTY_EYE_POSITION = @"basicV7.eyePosition";
/**
/**
 瘦鼻      thin nose
 */
static NSString * const BEAUTY_NOSE_THIN = @"basicV7.thinNose";
/**
 鼻翼      nose wing
 */
static NSString * const BEAUTY_NOSE_WING = @"basicV7.noseWing";
/**
 鼻子位置      nose position
 */
static NSString * const BEAUTY_NOSE_HEIGHT = @"basicV7.noseHeight";
/**
 * 鼻梁宽度     nose bridge width
 */
static NSString * const BEAUTY_NOSE_BRIDGE_WIDTH = @"basicV7.noseBridgeWidth";
/**
 * 鼻根      nasion
 */
static NSString * const BEAUTY_NASION = @"basicV7.nasion";
/**
 白牙        tooth beauty
 */
static NSString * const BEAUTY_TOOTH_WHITEN = @"beauty.toothWhiten";
/**
 祛皱      remove pounch
 */
static NSString * const BEAUTY_FACE_REMOVE_WRINKLE = @"beauty.removeWrinkle";
/**
 祛法令纹      wrinkle smooth
 */
static NSString * const BEAUTY_FACE_REMOVE_LAW_LINE = @"beauty.removeLawLine";
/**
 祛眼袋      remove eye pouch
 */
static NSString * const BEAUTY_FACE_REMOVE_EYE_BAGS = @"beauty.removeEyeBags";
/**
 嘴型      mouth size
 */
static NSString * const BEAUTY_MOUTH_SIZE = @"basicV7.mouthSize";
/**
 嘴唇宽度      mouth width
 */
static NSString * const BEAUTY_MOUTH_WIDTH = @"basicV7.mouthWidth";
/**
 嘴唇位置      mouth position
 */
static NSString * const BEAUTY_MOUTH_POSITION = @"basicV7.mouthPosition";
/**
 微笑唇      smile fale
 */
static NSString * const BEAUTY_SMILE_FACE = @"basicV7.smileFace";
/**
 嘴唇厚度      mouth height
 */
static NSString * const BEAUTY_MOUTH_HEIGHT = @"basicV7.mouthHeight";
/**
 眉毛角度     eyebrow angle
 */
static NSString * const BEAUTY_EYEBROW_ANGLE = @"basicV7.eyebrowAngle";
/**
 眉毛距离     eyebrow distance
 */
static NSString * const BEAUTY_EYEBROW_DISTANCE = @"basicV7.eyebrowDistance";
/**
 眉毛高度     eyebrow height
 */
static NSString * const BEAUTY_EYEBROW_HEIGHT = @"basicV7.eyebrowHeight";
/**
 眉毛长度     eyebrow length
 */
static NSString * const BEAUTY_EYEBROW_LENGTH = @"basicV7.eyebrowLength";
/**
 眉毛粗细     eyebrow thickness
 */
static NSString * const BEAUTY_EYEBROW_THICKNESS = @"basicV7.eyebrowThickness";
/**
 眉峰    eyebrow ridge
 */
static NSString * const BEAUTY_EYEBROW_RIDGE = @"basicV7.eyebrowRidge";
/**
 色温 image warmth
 */
static NSString * const BEAUTY_IMAGE_WARMTH = @"beauty.imageWarmth";
/**
 色调 image tint
 */
static NSString * const BEAUTY_IMAGE_TINT = @"beauty.imageTint";
/**
 亮度 image brightness
 */
static NSString * const BEAUTY_IMAGE_BRIGHTNESS = @"beauty.imageBrightness";
/**
 降噪 image denoise
 */
static NSString * const BEAUTY_IMAGE_DENOISE = @"postEffect.denoise";


#pragma mark - 美体      body

/**
 一键瘦身      auto thin BodyStrength
 */
static NSString * const BODY_AUTOTHIN_BODY_STRENGTH = @"body.autothinBodyStrength";
/**
 长腿      leg Stretch
 */
static NSString * const BODY_LEG_STRETCH = @"body.legStretch";
/**
 瘦腿      slim Leg Strength
 */
static NSString * const BODY_SLIM_LEG_STRENGTH = @"body.slimLegStrength";
/**
 瘦胳膊      slim arm Strength
 */
static NSString * const BODY_SLIM_ARM_STRENGTH = @"body.slimArmStrength";
/**
 瘦腰      waist Strength
 */
static NSString * const BODY_WAIST_STRENGTH = @"body.waistStrength";
/**
 瘦肩      thin Shoulder Strength
 */
static NSString * const BODY_THIN_SHOULDER_STRENGTH = @"body.thinShoulderStrength";
/**
 小头      slim Head Strength
 */
static NSString * const BODY_SLIM_HEAD_STRENGTH = @"body.slimHeadStrength";
/**
 胸部调整     enlarge chest strength
 */
static NSString * const BODY_ENLARGE_CHEST_STRENGTH = @"body.enlargeChestStrength";

#pragma mark - 美妆 makeup

/**
 美妆强度 makeup
 */
static NSString * const BeautyConstant_MAKEUP = @"makeup.strength";

#pragma mark - 滤镜/动效/分割/美妆      lut/Motion/segmentation/makeup

/**
 无
 */
static NSString * const XmagicProperty_ID_NONE = @"naught";

#pragma mark - 设置模型文件路径(setBundleToLightEngine)时传入的key

/**
 Light3DPlugin.bundle的路径对应的key
 */
static NSString * const AgentType_ACE_3D_AGENT = @"Ace_3d_Engine";
/**
 LightHandModel.bundle的路径对应的key
 */
static NSString * const AgentType_HAND_AGENT = @"HAND_AGENT";
/**
 LightBodyModel.bundle的路径对应的key
 */
static NSString * const AgentType_BODY_AGENT = @"BODY_AGENT";
/**
 LightBody3DModel.bundle的路径对应的key
 */
static NSString * const AgentType_BODY3D_POINT_AGENT = @"BODY3D_POINT_AGENT";
/**
 LightSegmentBody.bundle的路径对应的key
 */
static NSString * const AgentType_BG_SEG_AGENT = @"BG_SEG_AGENT";
/**
 LightSegmentHead.bundle的路径对应的key
 */
static NSString * const AgentType_HEAD_SEG_AGENT = @"HEAD_SEG_AGENT";
/**
 LightSegmentHair.bundle的路径对应的key
 */
static NSString * const AgentType_HAIR_SEG_AGENT = @"HAIR_SEG_AGENT";



#endif /* XmagicConstant_h */
