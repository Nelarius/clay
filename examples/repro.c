#include "../clay.h"

static char selected = 'B';

static void on_button_hover_A_handler(
    Clay_ElementId const element_id, Clay_PointerData const pointer, intptr_t user_data) {
    (void) (element_id);
    (void) (user_data);

    if (pointer.state == CLAY_POINTER_DATA_PRESSED_THIS_FRAME) {
        selected = 'A';
    }
}

static void on_button_hover_B_handler(
    Clay_ElementId const element_id, Clay_PointerData const pointer, intptr_t user_data) {
    (void) (element_id);
    (void) (user_data);

    if (pointer.state == CLAY_POINTER_DATA_PRESSED_THIS_FRAME) {
        selected = 'B';
    }
}

static void on_button_hover_C_handler(
    Clay_ElementId const element_id, Clay_PointerData const pointer, intptr_t user_data) {
    (void) (element_id);
    (void) (user_data);

    if (pointer.state == CLAY_POINTER_DATA_PRESSED_THIS_FRAME) {
        selected = 'C';
    }
}

Clay_RenderCommandArray repro_create_layout(int const width, int const height) {
    Clay_BeginLayout();

    Clay_Color const BUTTON_COLOR = (Clay_Color){74, 74, 74, 255};
    Clay_Color const BUTTON_COLOR_HOVERED = (Clay_Color){128, 128, 128, 255};
    Clay_Color const BUTTON_COLOR_SELECTED = (Clay_Color){180, 180, 180, 255};

    CLAY({
         .id = CLAY_ID("root"),
         .layout =
         {.childAlignment = {CLAY_ALIGN_X_LEFT, CLAY_ALIGN_Y_CENTER},
         .layoutDirection = CLAY_TOP_TO_BOTTOM,
         .padding = CLAY_PADDING_ALL(4),
         .sizing =
         {
         .width = CLAY_SIZING_FIT(0),
         .height = CLAY_SIZING_FIXED(height),
         }},
         }) {
        CLAY(
            {.id = CLAY_ID("section-buttons"),
            .layout = {
            .layoutDirection = CLAY_TOP_TO_BOTTOM, .padding = CLAY_PADDING_ALL(8)}}) {
            CLAY(
                {.id = CLAY_ID("A-button-padding"),
                .layout = {.padding = CLAY_PADDING_ALL(8)}}) {
                CLAY(
                    {.id = CLAY_ID("A-button"),
                    .backgroundColor = selected == 'A' ? BUTTON_COLOR_SELECTED :
                    (Clay_Hovered() ? BUTTON_COLOR_HOVERED : BUTTON_COLOR),
                    .layout = {
                    .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
                    .padding = CLAY_PADDING_ALL(4),
                    .sizing = {CLAY_SIZING_FIXED(30), CLAY_SIZING_FIXED(30)}}}) {
                    Clay_OnHover(
                        on_button_hover_A_handler,
                        0);
                    CLAY_TEXT(
                        CLAY_STRING("A"), CLAY_TEXT_CONFIG(
                            {.fontSize = 24,
                            .textColor = (Clay_Color){
                            255, 255, 255, 255}}));
                }
            }
            CLAY(
                {.id = CLAY_ID("B-button-padding"),
                .layout = {.padding = CLAY_PADDING_ALL(8)}}) {
                CLAY(
                    {.id = CLAY_ID("B-button"),
                    .backgroundColor = selected == 'B' ? BUTTON_COLOR_SELECTED :
                    (Clay_Hovered() ? BUTTON_COLOR_HOVERED : BUTTON_COLOR),
                    .layout = {
                    .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
                    .padding = CLAY_PADDING_ALL(4),
                    .sizing = {CLAY_SIZING_FIXED(30), CLAY_SIZING_FIXED(30)}}}) {
                    Clay_OnHover(
                        on_button_hover_B_handler,
                        0);
                    CLAY_TEXT(
                        CLAY_STRING("B"), CLAY_TEXT_CONFIG(
                            {.fontSize = 24,
                            .textColor = (Clay_Color){
                            255, 255, 255, 255}}));
                }
            }
            CLAY(
                {.id = CLAY_ID("C-button-padding"),
                .layout = {.padding = CLAY_PADDING_ALL(8)}}) {
                CLAY(
                    {.id = CLAY_ID("C-button"),
                    .backgroundColor = selected == 'C' ? BUTTON_COLOR_SELECTED : (Clay_Hovered() ?
                        BUTTON_COLOR_HOVERED : BUTTON_COLOR),
                    .layout = {
                    .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
                    .padding = CLAY_PADDING_ALL(4),
                    .sizing = {CLAY_SIZING_FIXED(30), CLAY_SIZING_FIXED(30)}}}) {
                    Clay_OnHover(
                        on_button_hover_C_handler,
                        0);
                    CLAY_TEXT(
                        CLAY_STRING("C"), CLAY_TEXT_CONFIG(
                            {.fontSize = 24,
                            .textColor = (Clay_Color){
                            255, 255, 255, 255}}));
                }
            }
        }
    }

    const Clay_RenderCommandArray commands = Clay_EndLayout();
    return commands;
}
