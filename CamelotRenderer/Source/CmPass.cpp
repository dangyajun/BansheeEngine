#include "CmPass.h"
#include "CmRasterizerState.h"
#include "CmBlendState.h"
#include "CmDepthStencilState.h"
#include "CmPassRTTI.h"
#include "CmException.h"

namespace CamelotEngine
{
    //-----------------------------------------------------------------------------
	Pass::Pass()
    { }
    //-----------------------------------------------------------------------------
	Pass::Pass(const Pass& oth)
    {
        *this = oth;
    }
    //-----------------------------------------------------------------------------
    Pass::~Pass()
    {
	
    }
    //-----------------------------------------------------------------------------
    Pass& Pass::operator=(const Pass& oth)
    {
	    // Default blending (overwrite)
	    mBlendState = oth.mBlendState;
		mRasterizerState = oth.mRasterizerState;
		mDepthStencilState = oth.mDepthStencilState;

		mVertexProgram = oth.mVertexProgram;
		mFragmentProgram = oth.mFragmentProgram;
		mGeometryProgram = oth.mGeometryProgram;

		return *this;
    }
    //-----------------------------------------------------------------------
    bool Pass::isTransparent(void) const
    {
		bool transparent = false;

		if(mBlendState != nullptr)
		{
			for(UINT32 i = 0; i < CM_MAX_MULTIPLE_RENDER_TARGETS; i++)
			{
				// Transparent if destination color is taken into account
				if (mBlendState->getDstBlend(i) != SBF_ZERO ||
					mBlendState->getSrcBlend(i) == SBF_DEST_COLOUR ||
					mBlendState->getSrcBlend(i) == SBF_ONE_MINUS_DEST_COLOUR ||
					mBlendState->getSrcBlend(i) == SBF_DEST_ALPHA ||
					mBlendState->getSrcBlend(i) == SBF_ONE_MINUS_DEST_ALPHA)
				{
					transparent = true;
				}
			}
		}

		return transparent;
    }
	//----------------------------------------------------------------------
	void Pass::setBlendState(BlendStatePtr blendState)
	{
		mBlendState = blendState;
	}
	//----------------------------------------------------------------------
	BlendStatePtr Pass::getBlendState() const
	{
		return mBlendState;
	}
	//----------------------------------------------------------------------
	void Pass::setRasterizerState(RasterizerStatePtr rasterizerState)
	{
		mRasterizerState = rasterizerState;
	}
	//----------------------------------------------------------------------
	RasterizerStatePtr Pass::getRasterizerState() const
	{
		return mRasterizerState;
	}
	//-----------------------------------------------------------------------
	void Pass::setDepthStencilState(DepthStencilStatePtr depthStencilState)
	{
		mDepthStencilState = depthStencilState;
	}
	//-----------------------------------------------------------------------
	DepthStencilStatePtr Pass::getDepthStencilState() const
	{
		return mDepthStencilState;
	}
    //-----------------------------------------------------------------------
	void Pass::setVertexProgram(GpuProgramHandle gpuProgram)
	{
		mVertexProgram = gpuProgram;
	}
    //-----------------------------------------------------------------------
	void Pass::setFragmentProgram(GpuProgramHandle gpuProgram)
	{
		mFragmentProgram = gpuProgram;
	}
	//-----------------------------------------------------------------------
	void Pass::setGeometryProgram(GpuProgramHandle gpuProgram)
	{
		mGeometryProgram = gpuProgram;
	}
	//-----------------------------------------------------------------------
	const GpuProgramHandle& Pass::getVertexProgram(void) const
	{
		return mVertexProgram;
	}
	//-----------------------------------------------------------------------
	const GpuProgramHandle& Pass::getFragmentProgram(void) const
	{
		return mFragmentProgram;
	}
	//-----------------------------------------------------------------------
	const GpuProgramHandle& Pass::getGeometryProgram(void) const
	{
		return mGeometryProgram;
	}
	//----------------------------------------------------------------------
	RTTITypeBase* Pass::getRTTIStatic()
	{
		return PassRTTI::instance();
	}
	//----------------------------------------------------------------------
	RTTITypeBase* Pass::getRTTI() const
	{
		return Pass::getRTTIStatic();
	}
}