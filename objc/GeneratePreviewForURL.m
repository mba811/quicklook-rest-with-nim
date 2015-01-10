#include <CoreFoundation/CoreFoundation.h>
#include <CoreServices/CoreServices.h>
#include <QuickLook/QuickLook.h>

#include "GeneratePreviewForURL.h"
//#include "rester.h"


OSStatus GeneratePreviewForURL(void *thisInterface, QLPreviewRequestRef preview, CFURLRef url, CFStringRef contentTypeUTI, CFDictionaryRef options);
void CancelPreviewGeneration(void *thisInterface, QLPreviewRequestRef preview);

/* -----------------------------------------------------------------------------
   Generate a preview for file

   This function's job is to create preview for designated file
   ----------------------------------------------------------------------------- */

OSStatus GeneratePreviewForURL(void *thisInterface, QLPreviewRequestRef preview, CFURLRef url, CFStringRef contentTypeUTI, CFDictionaryRef options)
{
    CFDataRef data = (CFDataRef) renderRst((NSURL*) url);

    if (data) {
		CFDictionaryRef props = (CFDictionaryRef) [NSDictionary dictionary];
        QLPreviewRequestSetDataRepresentation(preview, data, kUTTypeHTML, props);
    }

    return noErr;
}

void CancelPreviewGeneration(void *thisInterface, QLPreviewRequestRef preview)
{
    // Implement only if supported
}

NSData* renderRst(NSURL* url)
{
#if 1
    return nil;
#else
    return [NSData atawithcon]
    static BOOL did_init = NO;
    if (!did_init) {
        NimMain();
        did_init = YES;
    }
    char *path = (char*)[[url path] UTF8String];
    const long long total_bytes = txt_to_rst(path);

    NSMutableData *ret = [NSMutableData dataWithLength:total_bytes + 1];
    get_global_html((void*)[ret bytes]);
    return ret;
#endif
}
