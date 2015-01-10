#include <CoreFoundation/CoreFoundation.h>
#include <CoreServices/CoreServices.h>
#include <QuickLook/QuickLook.h>

#include "GeneratePreviewForURL.h"
#include "lazy_rest_c_api.h"


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
    static BOOL did_init = NO;
    if (!did_init) {
        NimMain();
        lr_set_global_rst_options("parser.enable.raw.directive = t");
        did_init = YES;
    }
    NSString* ext = [[url path] pathExtension];
    char *path = (char*)[[url path] UTF8String];
    char *html = 0;
    if ([@"rst" isEqualToString:ext] || [@"rest" isEqualToString:ext]) {
        // Treat input as restructured text.
        html = lr_safe_rst_file_to_html(path, NULL, NULL);
    } else {
        // Treat input as a source file.
        html = lr_source_file_to_html(path, NULL, 1, NULL);
    }

    NSData *ret = [NSData dataWithBytes:html length:strlen(html)];
    return ret;
}
