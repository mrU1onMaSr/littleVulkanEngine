#pragma once

#include "lve_window.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"

#include <cstdint>
#include <memory>
#include <vector>
#include <vulkan/vulkan_core.h>
#include <cassert>

namespace lve {
    class LveRenderer {
        public:
        LveRenderer(LveWindow &lveWindow, LveDevice &lveDevice);
        ~LveRenderer();

        LveRenderer(const LveWindow &) = delete;
        LveRenderer &operator=(const LveWindow &) = delete;

        VkRenderPass getSwapChainRenderPass() const {return lveSwapChain->getRenderPass();}
        bool isFrameInProgress() const {return isFrameStarted;}

        VkCommandBuffer getCurrentCommandBuffer() const {
            assert(isFrameStarted && "Cannot get frame buffer if frame isn't in progress");
            return commandBuffers[currentImageIndex];
        }

        VkCommandBuffer beginFrame();
        void endFrame();
        void beginSwapChainRenderPass(VkCommandBuffer commandBuffer);
        void endSwapChainRenderPass(VkCommandBuffer commandBuffer);

        private:
        void createCommandBuffers();
        void freeCommandBuffers();
        void recreateSwapChain();
        //void sierpinski(std::vector<LveModel::Vertex> &verticies, int depth, glm::vec2 left, glm::vec2 right, glm::vec2 top);

        LveWindow& lveWindow;
        LveDevice& lveDevice;
        std::unique_ptr<LveSwapChain> lveSwapChain;
        std::vector<VkCommandBuffer> commandBuffers;
        uint32_t currentImageIndex;
        bool isFrameStarted{false};
    };
}