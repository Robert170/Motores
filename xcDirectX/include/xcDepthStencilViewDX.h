#pragma once
#include "xcPrerequisitesDX.h"
#include "xcDepthStencilView.h"
namespace xcEngineSDK {
  class DepthStencilViewDX : public DepthStencilView
  {
	public:
		/// Destructor
		~DepthStencilViewDX();
	protected:
		/**
			* @brief protected functions
		*/

		/// Default Constructor
		DepthStencilViewDX() = default;

		/**
		 * @Variable m_DSV, pointer for the depth stencil view
		 */
		ID3D11DepthStencilView* m_pDSV = nullptr;

	

		friend class DXGraphiAPI;
  };
}

