#ifndef GDEXTENSION_SPX_WRAP_H
#define GDEXTENSION_SPX_WRAP_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#define NOT_GODOT_ENGINE
#include "gdextension_spx_ext.h"
#ifndef __cplusplus
typedef uint32_t char32_t;
typedef uint16_t char16_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef uintptr_t pointer;

extern void initialize(void *userdata, GDExtensionInitializationLevel p_level);
extern void deinitialize(void *userdata, GDExtensionInitializationLevel p_level);

static inline void initialization(GDExtensionInitialization *p_init) {
	p_init->initialize = initialize;
	p_init->deinitialize = deinitialize;
}

static inline void *get_proc_address(uintptr_t fn, const char* p_name) {
	return (void *)((GDExtensionInterfaceGetProcAddress)fn)(p_name);
}

// engine
extern void func_on_engine_start();  
extern void func_on_engine_update(GdFloat delta);  
extern void func_on_engine_destroy();  
// sprite
extern void func_on_sprite_ready(GdInt id);  
extern void func_on_sprite_updated(GdInt id);  
extern void func_on_sprite_destroyed(GdInt id);  
// input
extern void func_on_mouse_pressed(GdInt keyid);  
extern void func_on_mouse_released(GdInt keyid);  
extern void func_on_key_pressed(GdInt keyid);  
extern void func_on_key_released(GdInt keyid);  
extern void func_on_action_pressed(GdString action_name);  
extern void func_on_action_just_pressed(GdString action_name);  
extern void func_on_action_just_released(GdString action_name);  
extern void func_on_axis_changed(GdString action_name, GdFloat value);  
// physics
extern void func_on_collision_enter(GdInt self_id, GdInt other_id);  
extern void func_on_collision_stay(GdInt self_id, GdInt other_id);  
extern void func_on_collision_exit(GdInt self_id, GdInt other_id);  
extern void func_on_trigger_enter(GdInt self_id, GdInt other_id);  
extern void func_on_trigger_stay(GdInt self_id, GdInt other_id);  
extern void func_on_trigger_exit(GdInt self_id, GdInt other_id); 
// ui 
extern void func_on_ui_pressed(GdInt id);  
extern void func_on_ui_released(GdInt id);  
extern void func_on_ui_hovered(GdInt id);  
extern void func_on_ui_clicked(GdInt id);  
extern void func_on_ui_toggle(GdInt id, GdBool is_on);  
extern void func_on_ui_text_changed(GdInt id, GdString text);  

static inline void spx_global_register_callbacks(pointer fn) {
	SpxCallbackInfo info;
	SpxCallbackInfo* p_extension_funcs = &info;
    // engine
	p_extension_funcs->func_on_engine_start = func_on_engine_start;
	p_extension_funcs->func_on_engine_update = func_on_engine_update;
	p_extension_funcs->func_on_engine_destroy = func_on_engine_destroy;
    // sprite
	p_extension_funcs->func_on_sprite_ready = func_on_sprite_ready;
	p_extension_funcs->func_on_sprite_updated = func_on_sprite_updated;
	p_extension_funcs->func_on_sprite_destroyed = func_on_sprite_destroyed;
    // input
	p_extension_funcs->func_on_mouse_pressed = func_on_mouse_pressed;
	p_extension_funcs->func_on_mouse_released = func_on_mouse_released;
	p_extension_funcs->func_on_key_pressed = func_on_key_pressed;
	p_extension_funcs->func_on_key_released = func_on_key_released;
	p_extension_funcs->func_on_action_pressed = func_on_action_pressed;
	p_extension_funcs->func_on_action_just_pressed = func_on_action_just_pressed;
	p_extension_funcs->func_on_action_just_released = func_on_action_just_released;
	p_extension_funcs->func_on_axis_changed = func_on_axis_changed;
    // physics
	p_extension_funcs->func_on_collision_enter = func_on_collision_enter;
	p_extension_funcs->func_on_collision_stay = func_on_collision_stay;
	p_extension_funcs->func_on_collision_exit = func_on_collision_exit;
	p_extension_funcs->func_on_trigger_enter = func_on_trigger_enter;
	p_extension_funcs->func_on_trigger_stay = func_on_trigger_stay;
	p_extension_funcs->func_on_trigger_exit = func_on_trigger_exit;
    // ui
	p_extension_funcs->func_on_ui_pressed = func_on_ui_pressed;
	p_extension_funcs->func_on_ui_released = func_on_ui_released;
	p_extension_funcs->func_on_ui_hovered = func_on_ui_hovered;
	p_extension_funcs->func_on_ui_clicked = func_on_ui_clicked;
	p_extension_funcs->func_on_ui_toggle = func_on_ui_toggle;
	p_extension_funcs->func_on_ui_text_changed = func_on_ui_text_changed;
	((GDExtensionSpxGlobalRegisterCallbacks)fn)((GDExtensionSpxCallbackInfoPtr)p_extension_funcs);
}


#ifdef __cplusplus
}
#endif

#endif // GDEXTENSION_SPX_WRAP_H