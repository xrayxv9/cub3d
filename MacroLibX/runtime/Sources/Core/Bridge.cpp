#include <PreCompiled.h>

#include <Core/Application.h>
#include <Core/SDLManager.h>
#include <mlx.h>
#include <mlx_extended.h>
#include <Core/Memory.h>
#include <Core/Handles.h>
#include <Renderer/RenderCore.h>

static mlx::Application* __internal_application_ptr = nullptr;

#ifndef DISABLE_ALL_SAFETIES
	#define MLX_CHECK_APPLICATION_POINTER(ptr) \
		if(ptr == NULL || ptr->app.Get() != __internal_application_ptr) \
			mlx::FatalError("invalid mlx handle passed to '%'", MLX_FUNC_SIG); \
		else {} // just to avoid issues with possible if-else statements outside this macro
#else
	#define MLX_CHECK_APPLICATION_POINTER(ptr)
#endif

extern "C"
{
	mlx_context mlx_init()
	{
		if(__internal_application_ptr != nullptr)
		{
			mlx::Error("MLX cannot be initialized multiple times");
			return nullptr;
		}

		mlx::MemManager::Get(); // just to initialize the C garbage collector

		__internal_application_ptr = new mlx::Application;
		if(__internal_application_ptr == nullptr)
			mlx::FatalError("internal application memory allocation failed");

		mlx_context_handler* context = new mlx_context_handler;
		if(context == nullptr)
			mlx::FatalError("mlx_context memory allocation failed");
		context->app = __internal_application_ptr;
		return context;
	}

	void mlx_set_fps_goal(mlx_context mlx, int fps)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		if(fps < 0)
			mlx::Error("You cannot set a negative FPS cap (nice try)");
		else
			mlx->app->SetFPSCap(static_cast<std::uint32_t>(fps));
	}

	void mlx_destroy_context(mlx_context mlx)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		delete mlx;
		delete __internal_application_ptr;
		__internal_application_ptr = nullptr;
	}

	mlx_window mlx_new_window(mlx_context mlx, const mlx_window_create_info* info)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		return mlx->app->NewGraphicsSuport(info);
	}

	void mlx_destroy_window(mlx_context mlx, mlx_window win)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx->app->DestroyGraphicsSupport(win);
	}

	void mlx_set_window_position(mlx_context mlx, mlx_window win, int x, int y)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs && !gs->HasWindow())
			return;
		gs->GetWindow()->SetPosition(x, y);
	}

	void mlx_set_window_size(mlx_context mlx, mlx_window win, int width, int height)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs && !gs->HasWindow())
			return;
		gs->GetWindow()->SetSize(width, height);
	}

	void mlx_set_window_title(mlx_context mlx, mlx_window win, const char* title)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs && !gs->HasWindow())
			return;
		gs->GetWindow()->SetTitle(title);
	}

	void mlx_set_window_fullscreen(mlx_context mlx, mlx_window win, bool enable)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs && !gs->HasWindow())
			return;
		gs->GetWindow()->SetFullscreen(enable);
	}

	void mlx_get_window_position(mlx_context mlx, mlx_window win, int* x, int* y)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs && !gs->HasWindow())
			return;
		gs->GetWindow()->GetPosition(x, y);
	}

	void mlx_get_window_size(mlx_context mlx, mlx_window win, int* x, int* y)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs && !gs->HasWindow())
			return;
		gs->GetWindow()->GetSize(x, y);
	}

	void mlx_clear_window(mlx_context mlx, mlx_window win, mlx_color color)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		gs->ResetRenderData(color);
	}

	void mlx_get_screen_size(mlx_context mlx, mlx_window win, int* w, int* h)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		if(!gs->HasWindow())
		{
			*w = 0;
			*h = 0;
		}
		else
			gs->GetWindow()->GetScreenSizeWindowIsOn(w, h);
	}

	void mlx_add_loop_hook(mlx_context mlx, void(*f)(void*), void* param)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx->app->AddLoopHook(f, param);
	}

	void mlx_loop(mlx_context mlx)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx->app->Run();
	}

	void mlx_loop_end(mlx_context mlx)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx->app->LoopEnd();
	}

	void mlx_mouse_show(mlx_context mlx)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::SDLManager::ShowCursor();
	}

	void mlx_mouse_hide(mlx_context mlx)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::SDLManager::HideCursor();
	}

	void mlx_mouse_move(mlx_context mlx, mlx_window win, int x, int y)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs && !gs->HasWindow())
			return;
		gs->GetWindow()->MoveMouse(x, y);
	}

	void mlx_mouse_get_pos(mlx_context mlx, int* x, int* y)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx->app->GetMousePos(x, y);
	}

	void mlx_on_event(mlx_context mlx, mlx_window win, mlx_event_type event, void(*f)(int, void*), void* param)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx->app->OnEvent(win, static_cast<int>(event), f, param);
	}

	void mlx_pixel_put(mlx_context mlx, mlx_window win, int x, int y, mlx_color color)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		gs->PixelPut(x, y, color);
	}

	mlx_image mlx_new_image(mlx_context mlx, int width, int height)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		if(width <= 0 || height <= 0)
		{
			mlx::Error("invalid image size (% x %)", width, height);
			return nullptr;
		}
		return mlx->app->NewTexture(width, height);
	}

	mlx_image mlx_new_image_from_file(mlx_context mlx, char* filename, int* width, int* height)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		if (filename == nullptr)
		{
			mlx::Error("Image loader: filename is NULL");
			return nullptr;
		}
		std::filesystem::path file(filename);
		if(file.extension() != ".png" &&
			file.extension() != ".jpg" &&
			file.extension() != ".jpeg" &&
			file.extension() != ".bmp" &&
			file.extension() != ".dib")
		{
			mlx::Error("Image loader: not a valid file format '%'", filename);
			return nullptr;
		}
		return mlx->app->NewStbTexture(filename, width, height);
	}

	void mlx_destroy_image(mlx_context mlx, mlx_image image)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx->app->DestroyTexture(image);
	}

	mlx_color mlx_get_image_pixel(mlx_context mlx, mlx_image image, int x, int y)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::Texture> texture = mlx->app->GetTexture(image);
		if(!texture)
			return { .rgba = 0x00000000 };
		return texture->GetPixel(x, y);
	}

	void mlx_set_image_pixel(mlx_context mlx, mlx_image image, int x, int y, mlx_color color)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::Texture> texture = mlx->app->GetTexture(image);
		if(!texture)
			return;
		texture->SetPixel(x, y, color);
	}

	void mlx_put_image_to_window(mlx_context mlx, mlx_window win, mlx_image image, int x, int y)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		mlx::NonOwningPtr<mlx::Texture> texture = mlx->app->GetTexture(image);
		if(!texture)
			return;
		gs->TexturePut(texture, x, y, 1.0f, 1.0f, 0.0f);
	}

	void mlx_string_put(mlx_context mlx, mlx_window win, int x, int y, mlx_color color, char* str)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		if(str == nullptr)
		{
			mlx::Error("invalid text (NULL)");
			return;
		}
		if(std::strlen(str) == 0)
		{
			mlx::Warning("trying to put an empty text");
			return;
		}
		gs->StringPut(x, y, color, str);
	}

	void mlx_set_font(mlx_context mlx, char* filepath)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		if(filepath == nullptr)
		{
			mlx::Error("Font loader: filepath is NULL");
			return;
		}
		std::filesystem::path file(filepath);
		if(std::strcmp(filepath, "default") != 0 && file.extension() != ".ttf" && file.extension() != ".tte")
		{
			mlx::Error("TTF loader: not a truetype font file '%'", filepath);
			return;
		}
		if(std::strcmp(filepath, "default") == 0)
			mlx->app->LoadFont(file, 6.f);
		else
			mlx->app->LoadFont(file, 16.f);
	}

	void mlx_set_font_scale(mlx_context mlx, char* filepath, float scale)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		if(filepath == nullptr)
		{
			mlx::Error("Font loader: filepath is NULL");
			return;
		}
		std::filesystem::path file(filepath);
		if(std::strcmp(filepath, "default") != 0 && file.extension() != ".ttf" && file.extension() != ".tte")
		{
			mlx::Error("TTF loader: not a truetype font file '%'", filepath);
			return;
		}
		mlx->app->LoadFont(file, scale);
	}

	// Extended

	void mlx_set_window_max_size(mlx_context mlx, mlx_window win, int x, int y)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		gs->GetWindow()->SetMaxSize(x, y);
	}

	void mlx_set_window_min_size(mlx_context mlx, mlx_window win, int x, int y)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		gs->GetWindow()->SetMinSize(x, y);
	}

	void mlx_maximise_window(mlx_context mlx, mlx_window win)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		gs->GetWindow()->Maximize();
	}

	void mlx_minimize_window(mlx_context mlx, mlx_window win)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		gs->GetWindow()->Minimize();
	}

	void mlx_restore_window(mlx_context mlx, mlx_window win)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		gs->GetWindow()->Restore();
	}

	void mlx_pixel_put_array(mlx_context mlx, mlx_window win, int x, int y, mlx_color* pixels, size_t pixels_size)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		gs->PixelPutArray(x, y, pixels, pixels_size);
	}

	void mlx_pixel_put_region(mlx_context mlx, mlx_window win, int x, int y, int w, int h, mlx_color* pixels)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		gs->PixelPutRegion(x, y, w, h, pixels);
	}

	void mlx_get_image_region(mlx_context mlx, mlx_image image, int x, int y, int w, int h, mlx_color* dst)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::Texture> texture = mlx->app->GetTexture(image);
		if(!texture)
			return;
		texture->GetRegion(x, y, w, h, dst);
	}

	void mlx_set_image_region(mlx_context mlx, mlx_image image, int x, int y, int w, int h, mlx_color* pixels)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::Texture> texture = mlx->app->GetTexture(image);
		if(!texture)
			return;
		texture->SetRegion(x, y, w, h, pixels);
	}

	void mlx_put_transformed_image_to_window(mlx_context mlx, mlx_window win, mlx_image image, int x, int y, float scale_x, float scale_y, float angle)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		mlx::NonOwningPtr<mlx::Texture> texture = mlx->app->GetTexture(image);
		if(!texture)
			return;
		gs->TexturePut(texture, x, y, scale_x, scale_y, angle);
	}

	// Hidden bindings

	VkInstance mlx_get_vk_instance(mlx_context mlx)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		return mlx::RenderCore::Get().GetInstance();
	}

	VkPhysicalDevice mlx_get_vk_physical_device(mlx_context mlx)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		return mlx::RenderCore::Get().GetPhysicalDevice();
	}

	VkDevice mlx_get_vk_device(mlx_context mlx)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		return mlx::RenderCore::Get().GetDevice();
	}

	VkQueue mlx_get_vk_graphics_queue(mlx_context mlx)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		return kvfGetDeviceQueue(mlx::RenderCore::Get().GetDevice(), KVF_GRAPHICS_QUEUE);
	}

	unsigned int mlx_get_vk_graphics_queue_family(mlx_context mlx)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		return kvfGetDeviceQueueFamily(mlx::RenderCore::Get().GetDevice(), KVF_GRAPHICS_QUEUE);
	}

	mlx_function mlx_get_vk_fn(mlx_context mlx, const char* name)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		#define MLX_VULKAN_GLOBAL_FUNCTION(fn)   if(std::strcmp(name, #fn) == 0) return reinterpret_cast<mlx_function>(mlx::RenderCore::Get().fn);
		#define MLX_VULKAN_INSTANCE_FUNCTION(fn) if(std::strcmp(name, #fn) == 0) return reinterpret_cast<mlx_function>(mlx::RenderCore::Get().fn);
		#define MLX_VULKAN_DEVICE_FUNCTION(fn)   if(std::strcmp(name, #fn) == 0) return reinterpret_cast<mlx_function>(mlx::RenderCore::Get().fn);
			#include <Renderer/Vulkan/VulkanDefs.h>
		#undef MLX_VULKAN_GLOBAL_FUNCTION
		#undef MLX_VULKAN_INSTANCE_FUNCTION
		#undef MLX_VULKAN_DEVICE_FUNCTION

		return nullptr;
	}

	VkSurfaceKHR mlx_get_vk_surface(mlx_context mlx, mlx_window win)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return nullptr;
		return gs->GetRenderer().GetSwapchain().GetSurface();
	}

	VkImage mlx_get_vk_swapchain_image(mlx_context mlx, mlx_window win, unsigned int index)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs || index > gs->GetRenderer().GetSwapchain().GetImagesCount())
			return nullptr;
		return gs->GetRenderer().GetSwapchain().GetSwapchainImages()[index].Get();
	}

	unsigned int mlx_get_vk_swapchain_image_count(mlx_context mlx, mlx_window win)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return 0;
		return gs->GetRenderer().GetSwapchain().GetImagesCount();
	}

	VkImageView mlx_get_vk_swapchain_image_view(mlx_context mlx, mlx_window win, unsigned int index)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs || index > gs->GetRenderer().GetSwapchain().GetImagesCount())
			return nullptr;
		return gs->GetRenderer().GetSwapchain().GetSwapchainImages()[index].GetImageView();
	}

	unsigned int mlx_get_current_vk_swapchain_image_index(mlx_context mlx, mlx_window win)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return -1;
		return gs->GetRenderer().GetSwapchain().GetImageIndex();
	}

	VkExtent2D mlx_get_vk_swapchain_extent(mlx_context mlx, mlx_window win)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return {};
		return kvfGetSwapchainImagesSize(gs->GetRenderer().GetSwapchain().Get());
	}

	VkFormat mlx_get_vk_swapchain_format(mlx_context mlx, mlx_window win)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return VK_FORMAT_UNDEFINED;
		return kvfGetSwapchainImagesFormat(gs->GetRenderer().GetSwapchain().Get());
	}

	void* mlx_get_window_handle(mlx_context mlx, mlx_window win)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs || !gs->HasWindow())
			return nullptr;
		return mlx::SDLManager::Get().GetRawWindow(gs->GetWindow()->GetRawHandle());
	}

	void mlx_set_sdl_input_hook(mlx_context mlx, void(*f)(void*))
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::SDLManager::Get().SetInputBinding(f);
	}

	void mlx_add_pre_render_hook(mlx_context mlx, mlx_window win, void(*f)(VkCommandBuffer, void*), void* param)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		mlx::NonOwningPtr<mlx::GraphicsSupport> gs = mlx->app->GetGraphicsSupport(win);
		if(!gs)
			return;
		gs->AddPreRenderHook(f, param);
	}

	mlx_function mlx_get_proc_addr(mlx_context mlx, const char* name)
	{
		MLX_CHECK_APPLICATION_POINTER(mlx);
		#define MLX_MAKE_ENTRY(fn) { #fn, reinterpret_cast<mlx_function>(fn) }
		std::unordered_map<std::string, mlx_function> entries = {
			MLX_MAKE_ENTRY(mlx_get_vk_instance),
			MLX_MAKE_ENTRY(mlx_get_vk_surface),
			MLX_MAKE_ENTRY(mlx_set_sdl_input_hook),
			MLX_MAKE_ENTRY(mlx_get_vk_physical_device),
			MLX_MAKE_ENTRY(mlx_get_vk_graphics_queue),
			MLX_MAKE_ENTRY(mlx_get_vk_graphics_queue_family),
			MLX_MAKE_ENTRY(mlx_get_vk_device),
			MLX_MAKE_ENTRY(mlx_get_vk_fn),
			MLX_MAKE_ENTRY(mlx_get_window_handle),
			MLX_MAKE_ENTRY(mlx_get_vk_swapchain_image_count),
			MLX_MAKE_ENTRY(mlx_get_vk_swapchain_extent),
			MLX_MAKE_ENTRY(mlx_get_vk_swapchain_format),
			MLX_MAKE_ENTRY(mlx_get_vk_swapchain_image),
			MLX_MAKE_ENTRY(mlx_get_vk_swapchain_image_view),
			MLX_MAKE_ENTRY(mlx_get_current_vk_swapchain_image_index),
			MLX_MAKE_ENTRY(mlx_add_pre_render_hook),
		};
		auto it = entries.find(std::string{ name });
		if(it != entries.end())
			return it->second;
		return nullptr;
	}
}
