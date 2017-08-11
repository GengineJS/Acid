#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

#include <vulkan/vulkan.h>
#include <glfw/glfw3.h>

#include "../framework/framework.h"
#include "../stb/stb_image.h"

namespace flounder
{
	/// <summary>
	/// A module used for the creation, updating and destruction of the display.
	/// </summary>
	class display :
		public imodule
	{
	private:
		static const std::vector<const char*> VALIDATION_LAYERS;

		int m_windowWidth;
		int m_windowHeight;
		int m_fullscreenWidth;
		int m_fullscreenHeight;
		float m_aspectRatio;

		std::string m_title;
		std::string m_icon;
		float m_fpsLimit;
		bool m_vsync;
		bool m_antialiasing;
		int m_samples;
		bool m_fullscreen;

		GLFWwindow *m_window;
		bool m_closed;
		bool m_focused;
		int m_windowPosX;
		int m_windowPosY;

		bool m_validationLayers;

		VkInstance m_instance;
		VkPhysicalDevice m_physicalDevice;
		VkPhysicalDeviceProperties m_physicalDeviceProperties;
		std::vector<const char*> m_instanceLayerList;
		std::vector<const char*> m_instanceExtensionList;
		std::vector<const char*> m_deviceExtensionList;
		VkDebugReportCallbackEXT m_debugReport;
		VkDevice m_device;

		friend void callbackError(int error, const char *description);
		
		friend void callbackClose(GLFWwindow *window);
		
		friend void callbackFocus(GLFWwindow *window, int focused);
		
		friend void callbackPosition(GLFWwindow *window, int xpos, int ypos);
		
		friend void callbackSize(GLFWwindow *window, int width, int height);
		
		friend void callbackFrame(GLFWwindow *window, int width, int height);
		
		friend VKAPI_ATTR VkBool32 VKAPI_CALL vkCallbackDebug(VkDebugReportFlagsEXT messageFlags, VkDebugReportObjectTypeEXT objectType, uint64_t sourceObject,
			size_t location, int32_t messageCode, const char *layerPrefix, const char *message, void *userdata);

		VkResult fvkCreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
		
		void fvkDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);
	public:
		inline static void vkErrorCheck(VkResult result);

		/// <summary>
		/// Gets this framework instance.
		/// </summary>
		/// <returns> The current module instance. </returns>
		static display *get()
		{
			return static_cast<display*>(framework::get()->getInstance("display"));
		}

		/// <summary>
		/// Creates a new display module.
		/// </summary>
		display();

		/// <summary>
		/// Deconstructor for the display module.
		/// </summary>
		~display();

		void update() override;

		/// <summary>
		/// Takes a screenshot of the current image of the display and saves it into the screenshots folder a png image.
		/// </summary>
		void screenshot();

		/// <summary>
		/// Gets the width of the display in pixels.
		/// </summary>
		/// <returns> The width of the display. </returns>
		inline int getWidth() { return m_fullscreen ? m_fullscreenWidth : m_windowWidth; }

		/// <summary>
		/// Gets the non-fullscreen width of the display in pixels.
		/// </summary>
		/// <returns> The width of the display. </returns>
		inline int getWindowWidth() const { return m_windowWidth; }

		/// <summary>
		/// Gets the height of the display in pixels.
		/// </summary>
		/// <returns> The height of the display. </returns>
		inline int getHeight() { return m_fullscreen ? m_fullscreenHeight : m_windowHeight; }

		/// <summary>
		/// Gets the non-fullscreen height of the display in pixels.
		/// </summary>
		/// <returns> The height of the display. </returns>
		inline int getWindowHeight() const { return m_windowHeight; }

		/// <summary>
		/// Gets the aspect ratio between the displays width and height.
		/// </summary>
		/// <returns> The aspect ratio. </returns>
		inline float getAspectRatio() const { return m_aspectRatio; }

		/// <summary>
		/// Sets window size to a new size.
		/// </summary>
		/// <param name="width"> The new width in pixels. </param>
		/// <param name="height"> The new height in pixels. </param>
		void setWindowSize(const int &width, const int &height);

		/// <summary>
		/// Gets the window's title.
		/// </summary>
		/// <returns> The window's title. </returns>
		inline std::string getTitle() const { return m_title; }

		/// <summary>
		/// Sets window title
		/// </summary>
		/// <param name="title"> The new title. </param>
		void setTitle(const std::string &title);

		/// <summary>
		/// Gets the window's icon file.
		/// </summary>
		/// <returns> The window's icon file. </returns>
		inline std::string getIcon() const { return m_icon; }

		/// <summary>
		/// Sets window icon image.
		/// </summary>
		/// <param name="title"> The new icon file. </param>
		void setIcon(const std::string &icon);

		/// <summary>
		/// Gets the fps limit.
		/// </summary>
		/// <returns> The fps limit. </returns>
		inline float getFpsLimit() const { return m_fpsLimit; }

		/// <summary>
		/// Sets the fps limit. -1 disables limits.
		/// </summary>
		/// <param name="fpsLimit"> The new fps limit. </param>
		inline void setFpsLimit(const float &fpsLimit) { m_fpsLimit = fpsLimit; }

		/// <summary>
		/// Gets if the display is using vSync.
		/// </summary>
		/// <returns> If VSync is enabled. </returns>
		inline bool isVSync() const { return m_vsync; }

		/// <summary>
		/// Sets the display to use VSync or not.
		/// </summary>
		/// <param name="vsync"> Weather or not to use vSync. </param>
		inline void setVSync(const bool &vsync) { m_vsync = vsync; }

		/// <summary>
		/// Gets if the display requests antialiased images.
		/// </summary>
		/// <returns> If using antialiased images. </returns>
		inline bool isAntialiasing() const { return m_antialiasing; }

		/// <summary>
		/// Requests the display to antialias.
		/// </summary>
		/// <param name="antialiasing"> If the display should antialias. </param>
		inline void setAntialiasing(const bool &antialiasing) { m_antialiasing = antialiasing; }

		/// <summary>
		/// Gets how many MSAA samples should be done before swapping buffers.
		/// </summary>
		/// <returns> Amount of MSAA samples. </returns>
		inline int getSamples() const { return m_samples; }

		/// <summary>
		/// Gets how many MSAA samples should be done before swapping buffers. Zero disables multisampling. GLFW_DONT_CARE means no preference.
		/// </summary>
		/// <param name="samples"> The amount of MSAA samples. </param>
		inline void setSamples(const int &samples) { m_samples = samples; }

		/// <summary>
		/// Gets weather the display is fullscreen or not.
		/// </summary>
		/// <returns> Fullscreen or windowed. </returns>
		inline bool isFullscreen() const { return m_fullscreen; }

		/// <summary>
		/// Sets the display to be fullscreen or windowed.
		/// </summary>
		/// <param name="fullscreen"> Weather or not to be fullscreen. </param>
		void setFullscreen(const bool &fullscreen);

		/// <summary>
		/// Gets the current GLFW window.
		/// </summary>
		/// <returns> The current GLFW window. </returns>
		inline GLFWwindow *getWindow() const { return m_window; }

		/// <summary>
		/// Gets if the GLFW display is closed.
		/// </summary>
		/// <returns> If the GLFW display is closed. </returns>
		inline bool isClosed() const { return m_closed; }

		/// <summary>
		/// Gets if the GLFW display is selected.
		/// </summary>
		/// <returns> If the GLFW display is selected. </returns>
		inline bool isFocused() const { return m_focused; }

		/// <summary>
		/// Gets the windows Y position of the display in pixels.
		/// </summary>
		/// <returns> The windows x position. </returns>
		inline int getWindowXPos() const { return m_windowPosX; }

		/// <summary>
		/// Gets the windows Y position of the display in pixels.
		/// </summary>
		/// <returns> The windows Y position. </returns>
		inline int getWindowYPos() const { return m_windowPosY; }

		/// <summary>
		/// Gets the current Vulkan instance.
		/// </summary>
		/// <returns> The current Vulkan instance. </returns>
		inline VkInstance getVkInstance() const { return m_instance; }

		/// <summary>
		/// Gets the current Vulkan physical device (gpu).
		/// </summary>
		/// <returns> The current Vulkan physical device (gpu). </returns>
		inline VkPhysicalDevice getVkPhysicalDevice() const { return m_physicalDevice; }

		inline VkPhysicalDeviceProperties getVkProperties() const { return m_physicalDeviceProperties; }

		/// <summary>
		/// Gets the current Vulkan device.
		/// </summary>
		/// <returns> The current Vulkan device. </returns>
		inline VkDevice getVkDevice() const { return m_device; }
	};
}